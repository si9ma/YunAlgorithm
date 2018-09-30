//
// Created by si9ma on 9/30/18.
//

#include <cstdlib>
#include <iostream>
#include "matrix.h"

namespace si9ma{
    Matrix::Matrix(int row_len, int col_len, int val, bool is_random, bool is_square) {
        if(is_random)
            generate_random_matrix(row_len,col_len,val,is_square);
        else{
            this->row_len = row_len;
            this->col_len = col_len;
            if (is_square)
                this->col_len = row_len;

            array = new int*[row_len];
            for (int i = 0; i < row_len; ++i) {
                array[i] = new int[col_len];
                for (int j = 0; j <col_len; ++j) {
                    array[i][j] = val;
                }
            }
        }
    }

    void Matrix::generate_random_matrix(int max_row, int max_col, int max_val, bool is_square) {
        row_len = rand() % max_row + 1;
        col_len = rand() % max_col + 1;
        if (is_square)
            col_len = row_len;

        array = new int*[row_len];
        for (int i = 0; i < row_len; ++i) {
            array[i] = new int[col_len];
            for (int j = 0; j <col_len; ++j) {
                array[i][j] = (rand() % max_val) - (rand() % max_val); // -(max_val - 1) ~ max_val - 1
            }
        }

    }

    Matrix::~Matrix() {
        // delete every line
        for (int i = 0; i < row_len; ++i) {
            delete [] array[i];
        }

        delete [] array;
    }

    void Matrix::print_matrix(string separator) {
        for (int i = 0; i < row_len; ++i) {
            for (int j = 0; j < col_len; ++j) {
                std::cout << array[i][j] << separator;
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    void Matrix::print_matrix_rotate(string separator) {
        int r1 = 0, c1 = 0;
        int r2 = row_len - 1;
        int c2 = col_len - 1;

        while (r1 <= r2 && c1 <= c2)
            print_rectangle(r1++,c1++,r2--,c2--);

        std::cout <<  "\n\n";
    }

    void Matrix::print_rectangle(int r1, int c1, int r2, int c2,string separator) {
        // just one line
        if (r1 == r2){
            for (int i = c1; i <= c2; ++i) {
                std::cout << array[r1][i] << separator;
            }

            return;
        }

        // just one column
        if (c1 == c2){
            for (int i = r1; i <= r2 ; ++i) {
                std::cout << array[i][c1] << separator;
            }

            return;
        }

        int cur_row = r1;
        int cur_col = c1;

        while (cur_col != c2)
            std::cout << array[cur_row][cur_col++] << separator;

        while (cur_row != r2)
            std::cout << array[cur_row++][cur_col] << separator;

        while (cur_col != c1)
            std::cout << array[cur_row][cur_col--] << separator;

        while (cur_row != r1)
            std::cout << array[cur_row--][cur_col] << separator;
    }

    void Matrix::rotate_square(int r1, int c1, int r2, int c2) {
        if (r2 - r1 != c2 - c1)
            throw "not square";

        int rotate_group_num = r2 - r1;

        for (int i = 0; i < rotate_group_num; ++i) {
            int tmp = array[r2 - i][c1];
            array[r2 - i][c1] = array[r2][c2 - i];
            array[r2][c2 - i] = array[r1 + i][c2];
            array[r1 + i][c2] = array[r1][c1 + i];
            array[r1][c1 + i] = tmp;
        }
    }

    void Matrix::rotate_matrix() {
        if (row_len != col_len)
            throw "not square matrix";

        int r1 = 0,c1 = 0;
        int r2 = row_len - 1;
        int c2 = r2;

        while (r1 < r2)
            rotate_square(r1++,c1++,r2--,c2--);
    }

    void Matrix::print_line(int r1, int c1, int r2, int c2, bool is_down_to_up,string separator) {
        if (is_down_to_up){
            while (r1 >= r2)
                std::cout << array[r1--][c1++] << separator;
        } else{
            while (r2 <= r1)
                std::cout << array[r2++][c2--] << separator;
        }
    }

    void Matrix::print_matrix_round(string separator) {
        int r1 = 0,c1 = 0,r2 = 0,c2 = 0;
        int end_row = row_len - 1;
        int end_col = col_len - 1;

        bool is_down_to_up = true;
        while (r2 < row_len){
            print_line(r1,c1,r2,c2,is_down_to_up);
            c1 = r1 == end_row ? c1 + 1 : c1;
            r1 = r1 == end_row? r1 : r1 + 1;
            r2 = c2 == end_col ? r2 + 1 : r2;
            c2 = c2 == end_col ? c2: c2 + 1;
            is_down_to_up = !is_down_to_up;
        }

        std::cout << std::endl;
    }
}

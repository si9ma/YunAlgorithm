//
// Created by si9ma on 9/30/18.
//

#ifndef ALGORITHM_MATRIX_H
#define ALGORITHM_MATRIX_H

#include <string>
using std::string;

namespace si9ma {
    class Matrix {
    private:
        int row_len;
        int col_len;
        int **array;
        void generate_random_matrix(int max_row,int max_col,int max_val,bool is_square);
        void print_rectangle(int r1,int c1,int r2,int c2,string separator = " ");
        void rotate_square(int r1,int c1,int r2,int c2);
        void print_line(int r1,int c1,int r2,int c2, bool is_down_to_up,string separator = " ");

    public:
        Matrix() = default;

        // when is_random is true,row_len/col_len/val are random value < row_len/col_len/val
        Matrix(int row_len,int col_len,int val, bool is_random, bool is_square);

        ~Matrix();

        void print_matrix(string separator = " ");

        void print_matrix_rotate(string separator = " ");

        void rotate_matrix();

        void print_matrix_round(string separator = " ");
    };
}

#endif //ALGORITHM_MATRIX_H

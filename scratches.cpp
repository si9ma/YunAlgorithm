//
// Created by si9ma on 10/2/18.
//

#include <iostream>
#include "scratches.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_scratches_test = false;

bool test_scratches(){
    vector<string> str_arr = {"a","ac","mnlbzxtgdacwmqvykwjgixa","eurpyngnmilbtmjpsabesfx","ab","abd","abc","abb","acd","aca"};

    sort(str_arr.begin(),str_arr.end());
    stable_sort(str_arr.begin(),str_arr.end(), [](const string a, const string b) {return a.size() > b.size(); });

    for(string item:str_arr){
        cout << item << endl;
    }
}

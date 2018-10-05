//
// Created by si9ma on 10/5/18.
//

#include "lowest_lexicography.h"
#include <algorithm>

namespace si9ma{

    bool cmp(const string &str1,const string &str2){
        return str1 + str2 < str2 + str1;
    }

    string LowestLexicography::lowest_lexicography(vector<string> &strs) {

        std::sort(strs.begin(),strs.end(),cmp);

        string res = "";
        for (string str:strs){
            res += str;
        }

        return res;
    }
}

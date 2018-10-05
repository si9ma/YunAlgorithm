//
// Created by si9ma on 10/5/18.
//

#ifndef ALGORITHM_LOWEST_LEXICOGRAPHY_H
#define ALGORITHM_LOWEST_LEXICOGRAPHY_H

#include <string>
#include <vector>

using namespace std;

namespace si9ma {
    class LowestLexicography {

    public:
        LowestLexicography() = default;
        ~LowestLexicography() = default;
        static string lowest_lexicography(vector<string> &strs);
    };
}


#endif //ALGORITHM_LOWEST_LEXICOGRAPHY_H

//
// Created by si9ma on 10/4/18.
//

#ifndef ALGORITHM_HASH_H
#define ALGORITHM_HASH_H


#include <unordered_map>
#include <string>

using namespace std;

namespace si9ma {
    class RandomPool {
    private:
        int pool_size;
        unordered_map<string,int > key_map;
        unordered_map<int,string> index_map;

    public:
        RandomPool();
        ~RandomPool() = default;

        void put(string key);
        string get_random();
        void delete_key(string key);
    };
}

#endif //ALGORITHM_HASH_H

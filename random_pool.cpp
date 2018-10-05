//
// Created by si9ma on 10/4/18.
//

#include "random_pool.h"

namespace si9ma{
    RandomPool::RandomPool() {
        pool_size = 0;
    }

    void RandomPool::put(string key) {
        key_map[key] = ++pool_size;
        index_map [pool_size] = key;
    }

    void RandomPool::delete_key(string key) {
        int delete_index = key_map[key];
        index_map[delete_index] = index_map[pool_size];
        key_map.erase(key);
        index_map.erase(pool_size--);
    }

    string RandomPool::get_random() {
        int index = rand() % pool_size + 1;
        return index_map[index];
    }
}

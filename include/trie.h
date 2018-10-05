//
// Created by si9ma on 10/5/18.
//

#ifndef ALGORITHM_TRIE_H
#define ALGORITHM_TRIE_H

#include <string>
#include <iostream>

using namespace std;

namespace si9ma {
    struct TrieNode{
        int pass = 0;
        int end = 0;
        TrieNode * nexts[26] = {};

        TrieNode(int pass,int end):pass(pass),end(end){}
        ~TrieNode(){
            cout << "destroy" << endl;
        }
    };

    class Trie {
    public:
        static void insert(TrieNode *root,const string &str);
        static int search(TrieNode *root,const string &str);
        static int prefix_search(TrieNode *root,const string &str);
        static void delete_str(TrieNode *root,const string &str);
        static void destroy(TrieNode *root);
    };
}


#endif //ALGORITHM_TRIE_H

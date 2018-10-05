//
// Created by si9ma on 10/5/18.
//

#include "trie.h"

namespace si9ma{
    void Trie::insert(TrieNode *root,const string &str) {
        root->pass ++;
        auto *cur = root;

        for (int i = 0; i < str.length(); ++i) {
            int index = str[i] - 'a';

            if (cur->nexts[index] == nullptr){
                cur->nexts[index] = new TrieNode(0,0);
            }
            cur->nexts[index]->pass++;
            cur = cur->nexts[index];
        }

        cur->end ++;
    }

    void Trie::delete_str(TrieNode *root,const string &str) {
        if (search(root,str) > 0) {
            root->pass--;
            auto *cur = root;
            auto *next = root;

            for (int i = 0; i < str.length(); ++i) {
                int index = str[i] - 'a';

                next = cur->nexts[index];

                // if next pass == 0,reset cur next ptr to null
                if (--cur->nexts[index]->pass == 0)
                    cur->nexts[index] = nullptr;

                // delete cur,if pass == 0
                if (cur->pass == 0)
                    delete cur;

                cur = next;
            }

            cur->end--;

            // delete last is pass == null
            if (cur->pass == 0)
                delete cur;
        }
    }

    int Trie::prefix_search(TrieNode *root,const string &str) {
        auto *cur = root;

        for (int i = 0; i < str.length(); ++i) {
            int index = str[i] - 'a';

            if (cur->nexts[index] == nullptr)
                return 0;

            cur = cur->nexts[index];
        }

        return cur->pass;
    }

    int Trie::search(TrieNode *root,const string &str) {
        auto *cur = root;

        for (int i = 0; i < str.length(); ++i) {
            int index = str[i] - 'a';

            if (cur->nexts[index] == nullptr){
                return 0;
            }
            cur = cur->nexts[index];
        }

        return cur->end;
    }

    void Trie::destroy(TrieNode *root) {
        if (root == nullptr)
            return;

        for (int i = 0; i < 26; ++i) {
            destroy(root->nexts[i]);
        }

        delete root;
    }
}

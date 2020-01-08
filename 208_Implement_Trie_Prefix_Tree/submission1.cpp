#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root_ = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ptr = root_;
        for (auto s : word) {
            if (!ptr->children_[s - 'a']) {
                ptr->children_[s - 'a'] = new TrieNode();
            }
            ptr = ptr->children_[s - 'a'];
        }
        ptr->isWord_ = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ptr = find(word);
        return ptr && ptr->isWord_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr = find(prefix);
        return ptr != nullptr;
    }
    
private:
    struct TrieNode {
        bool isWord_;
        vector<TrieNode*> children_;
        TrieNode()
            : isWord_(false)
            , children_(26, nullptr){
        }     
    };
    TrieNode* find(string str) {
        TrieNode* ptr = root_;
        for (auto s : str) {
            ptr = ptr->children_[s - 'a'];
            if (!ptr) {
                return nullptr;
            }
        }
        return ptr;
    }
    TrieNode* root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> umap;
        istringstream get(str);
        int i = 0;
        for (string word; get>>word; i++) {
            if (i >= pattern.size()) {
                continue;
            }
            if (umap.count(pattern[i]) != 0) {
                if (umap[pattern[i]] != word) {
                    return false;
                }
            }
            else {
                for (auto n : umap) {
                    if (n.second == word) {
                        return false;
                    }
                }
                umap[pattern[i]] = word;
            }
        }
        return i == pattern.size();
    }
};
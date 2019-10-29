#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> umap1;
        unordered_map<string, int> umap2;
        istringstream get(str);
        int i = 0;
        for (string word; get>>word; i++) {
            if (i >= pattern.size()) {
                continue;
            }          
            if (umap1.find(pattern[i]) != umap1.end()) {
                if (umap2.find(word) == umap2.end()) {
                    return false;
                }
                if (umap2.find(word)->second != umap1.find(pattern[i])->second){
                    return false;
                }
            }
            else {
                if (umap2.find(word) != umap2.end()) {
                    return false;
                }
            }
            umap1[pattern[i]] = i;
            umap2[word] = i;
        }
        return i == pattern.size();
    }
};
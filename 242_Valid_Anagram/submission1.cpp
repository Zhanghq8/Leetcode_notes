#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> umap1, umap2;
        for (int i=0; i<s.size(); i++) {
            umap1[s[i]]++;
            umap2[t[i]]++;
        }
        for (auto it=umap1.begin(); it!=umap1.end(); it++) {
            if (umap1[it->first] != umap2[it->first]) {
                return false;
            }
        }
        return true;
    }
};
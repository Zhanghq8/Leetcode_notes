#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;
        for (int i = 0; i < s.size(); i++) {
            umap[s[i]]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            return umap[a] > umap[b] || (umap[a] == umap[b] && a > b);
        });
        return s;
    }
};
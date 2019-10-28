#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char, int> umap{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                   {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i=0; i<s.size(); i++) {
            if (i == s.size()-1 || umap[s[i]] >= umap[s[i+1]]) {
                result += umap[s[i]];
            }
            else {
                result -= umap[s[i]];
            }
        }
        return result;
    }
};
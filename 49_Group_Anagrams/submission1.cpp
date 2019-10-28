#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> str;
        for (int i=0; i<strs.size(); i++) {
            string str_sort = strs[i];
            sort(str_sort.begin(), str_sort.end());
            str[str_sort].push_back(strs[i]);
        }
        for (auto n:str) {
            result.push_back(n.second);
        }
        return result;
    }
};
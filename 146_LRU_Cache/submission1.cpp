#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        unordered_map<string, int> umap;
        umap[""] = 1;
        return numWays(s, umap);
    }
private:
    int numWays(string s, unordered_map<string, int>& umap) {
        if (umap.count(s)) {
            return umap[s];
        }
        if (s[0] == '0') {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        }
        int ways = numWays(s.substr(1), umap);
        int prefix = stoi(s.substr(0, 2));
        if (prefix <= 26) {
            ways += numWays(s.substr(2), umap);
        }
        umap[s] = ways;
        return ways;
    }
};
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> hashS(26, 0);
        vector<int> hashP(26, 0);
        for (int i = 0; i < p.size(); i++) {
            hashP[p[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i >= p.size()) {
                hashS[s[i - p.size()] - 'a']--;
            }
            hashS[s[i] - 'a']++;
            if (hashS == hashP) {
                result.push_back(i - p.size() + 1);
            }
        }
        return result;
    }
};
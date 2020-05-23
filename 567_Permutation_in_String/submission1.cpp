#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hashS1(26, 0);
        vector<int> hashS2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            hashS1[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++) {
            if (i >= s1.size()) {
                hashS2[s2[i - s1.size()] - 'a']--;
            }
            hashS2[s2[i] - 'a']++;
            if (hashS1 == hashS2) {
                return true;
            }
        }
        return false;
    }
};
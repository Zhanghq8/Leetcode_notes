#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            hash[s1[i] - 'a']++;
        }
        int left = 0, right = 0;
        int count = 0;
        for (; right < s2.size(); right++) {
            hash[s2[right] - 'a']--;
            if (hash[s2[right] - 'a'] >= 0) {
                count++;
            }
            if (right >= s1.size()) {
                hash[s2[left] - 'a']++;
                if (hash[s2[left] - 'a'] > 0) {
                    count--;
                }
                left++;
            }
            if (count == s1.size()) {
                return true;
            }
        }
        return false;
    }
};
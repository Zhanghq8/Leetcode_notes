#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> hash(26, 0);
        for (int i = 0; i < p.size(); i++) {
            hash[p[i] - 'a']++;
        }
        int left = 0, right = 0;
        int count = 0;
        for (; right < s.size(); right++) {
            hash[s[right] - 'a']--;
            if (hash[s[right] - 'a'] >= 0) {
                count++;
            }
            if (right >= p.size()) {
                hash[s[left] - 'a']++;
                if (hash[s[left] - 'a'] > 0) {
                    count--;
                }
                left++;
            }
            if (count == p.size()) {
                result.push_back(left);
            }
        }
        return result;
    }
};
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        int maxcnt = 0;
        int left = 0;
        vector<int> countchar(26, 0);
        for (int i=0; i<s.size(); i++) {
            countchar[s[i]- 'A']++;
            if (maxcnt < countchar[s[i] - 'A']) {
                maxcnt = countchar[s[i] - 'A'];
            }
            if (i - left + 1 - maxcnt <= k) {
                result = i - left + 1;
            }
            else {
                result = maxcnt + k;
                countchar[s[left] - 'A']--;
                left++;
            }
        }
        return result;
    }
};
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cntCapital = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] <= 'Z') {
                cntCapital++;
            }
        }
        return cntCapital == 0 || cntCapital == word.size() || (cntCapital == 1 && word[0] <= 'Z');
    }
};
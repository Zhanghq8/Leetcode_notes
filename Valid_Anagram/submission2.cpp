#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int array1[26] = {0};
        int array2[26] = {0};
        for (int i=0;i<s.size(); i++) {
            array1[s[i] - 'a']++;
            array2[t[i] - 'a']++;
        }
        for (int i=0; i<26; i++) {
            if (array1[i] != array2[i]) {
                return false;
            }
        }
        return true;
    }
};
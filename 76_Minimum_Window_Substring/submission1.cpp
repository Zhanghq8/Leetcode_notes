#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dic;
        unordered_map<char, int> word;
        int result = INT_MAX;
        string output = "";
        for (int i = 0; i < t.size(); i++) {
            dic[t[i]]++;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        for (; right < s.size(); right++) {
            if (dic.count(s[right])) {
                word[s[right]]++;
                if (word[s[right]] <= dic[s[right]]) {
                    count++;
                }
            }
            if (count >= t.size()) {
                while (!dic.count(s[left]) || word[s[left]] > dic[s[left]]) {
                    word[s[left]]--;
                    left++;
                }
                if (right - left + 1 < result) {
                    result = right - left + 1;
                    output = s.substr(left, result);
                }
            }
        }
        return output;
    }
};
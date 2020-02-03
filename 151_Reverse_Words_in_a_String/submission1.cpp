#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int wordStart = 0;
        int wordEnd = 0;
        while (wordStart != s.size()) {
            while (wordEnd < s.size() && s[wordEnd] != ' ') {
                wordEnd++;
            }
            reverse(s.begin() + wordStart, s.begin() + wordEnd);
            wordStart = wordEnd;
            while (wordStart < s.size() && s[wordStart] == ' ') {
                wordStart++;
                wordEnd++;
            }
        }
        wordStart = 0;
        wordEnd = 0;
        while (wordEnd < s.size()) {
            bool newWord = false;
            while (wordEnd < s.size() && s[wordEnd] == ' ') {
                newWord = true;
                wordEnd++;
            }
            if (wordEnd == s.size()) {
                break;
            } 
            if (newWord && wordStart > 0) {
                s[wordStart] = ' ';
                wordStart++;
            }
            s[wordStart] = s[wordEnd];
            wordStart++;
            wordEnd++;
        }
        return s.substr(0, wordStart);
    }
};
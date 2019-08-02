#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Stack

class Solution {
public:
    string addBinary(string a, string b) {
        stack<char> s1;
        stack<char> s2;
        string result = "";
        for (int i=0; i<a.size(); i++) {
            s1.push(a[i]);
        }
        for (int i=0; i<b.size(); i++) {
            s2.push(b[i]);
        }
        int carry = 0;
        int cnt = 0;
        while (cnt < a.size() || cnt < b.size() || carry != 0) {
            int sum;
            if (cnt < a.size() && cnt < b.size()) {
                sum = char2int(s1.top()) + char2int(s2.top()) + carry;
                s1.pop();
                s2.pop();
            }
            else if (cnt < a.size()) {
                sum = char2int(s1.top()) + carry;
                s1.pop();
            }
            else if (cnt < b.size()) {
                sum = char2int(s2.top()) + carry;
                s2.pop();
            }
            else {
                sum = carry;
            }
            carry = sum / 2;
            result.push_back(int2char(sum % 2));
            cnt++;
        }
        reverse(result.begin(), result.end());
        return result;
    }
private:
    int char2int(char a) {
        if (a == '1') {
            return 1;
        }
        else {
            return 0;
        }
    }
    char int2char(int a) {
        if (a == 1) {
            return '1';
        }
        else {
            return '0';
        }
    }
};
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Two pointers

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int indexa = a.size()-1;
        int indexb = b.size()-1;
        int carry = 0;
        while (indexa >=0 || indexb >= 0 || carry != 0) {
            int sum;
            if (indexa >=0 && indexb >= 0) {
                sum = char2int(a[indexa]) + char2int(b[indexb]) + carry;
                indexa--;
                indexb--;
            }
            else if (indexa >=0) {
                sum = char2int(a[indexa]) + carry;
                indexa--;
            }
            else if (indexb >=0) {
                sum = char2int(b[indexb]) + carry;
                indexb--;
            }
            else {
                sum = carry;
            }
            carry = sum / 2;
            result.push_back(int2char(sum % 2));
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
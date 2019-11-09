#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> value {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbol {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result = "";
        int copy_num = num;
        int index = 0;
        while (copy_num > 0 && index < value.size()) {
            if (copy_num - value[index] >= 0) {
                result += symbol[index];
                copy_num -= value[index];
            }
            else {
                index++;
            }
        }
        return result;
    }
};
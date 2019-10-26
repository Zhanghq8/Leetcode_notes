#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }  
        int index = 0;
        int sign = 1;
        bool end_flag = false;
        int result = 0;
        while(index<str.size() && str[index] == ' ') {
            index++;
        }
        if (index<str.size() && (str[index] == '-' || str[index] == '+')) {
            if (str[index] == '-') {
                sign = -1;
            }
            index++;
        }
        while (index<str.size() && str[index] >= '0' && str[index] <= '9') {
            if (result > INT_MAX/10 && sign == 1) {
                return INT_MAX;
            }
            else if (result > INT_MAX/10 && sign == -1){
                return INT_MIN;
            }
            else if (result == INT_MAX/10 && (str[index] - '0' >= 8 && sign == 1)) {
                return INT_MAX;
            }
            else if (result == INT_MAX/10 && (str[index] - '0' >= 8 && sign == -1)) {
                return INT_MIN;
            }
            result = result*10 + (str[index] - '0');
            index++;
        }
        return result*sign;
    }
};

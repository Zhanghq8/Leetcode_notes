#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int posSign = 1;
        int index = 0;
        int result = 0;
        while (str[index] == ' ') {
            index++;
        }
        if (str[index] == '-') {
            posSign = -1;
            index++;
        } else if (str[index] == '+') {
            index++;
        } else if (str[index] - '0' < 0 || str[index] - '9' > 0) {
            return result;
        } 
        for (int i = index; i < str.size(); i++) {
            if (str[i] - '0' < 0 || str[i] - '9' > 0) {
                return result * posSign;
            }
            if ((result > INT_MAX/10 && posSign == 1) || (result == INT_MAX/10 && posSign == 1 && str[i] - '0' >= 8)) {
                return INT_MAX;
            } else if ((result > INT_MAX/10 && posSign == -1) || (result == INT_MAX/10 && posSign == -1 && str[i] - '0' >= 8)) {
                return INT_MIN;
            } else {
                result = result * 10 + (str[i] - '0');
            }
        }
        return result * posSign;
    }
};
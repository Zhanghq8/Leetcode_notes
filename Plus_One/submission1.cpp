#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size()-1;
        int result = -1;
        while (length >= 0 && result != 10) {
            result = digits[length];
            if (result+1 != 10) {
                digits[length] += 1;
                return digits;
            }
            else {
                digits[length] = 0;
            }
            length--;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result = "";
        int length = s.size();
        int index = 2*numRows - 2;
        for (int i=0; i<numRows; i++) {
            for (int j=0; j<length; j += index) {
                if (i + j < length) {
                    result += s[i + j];
                    if (i != 0 && i != numRows-1) {
                        if (i + j + index - 2 * i < length) {
                            result += s[i + j + index - 2 * i];
                        }
                    }   
                }
            }
        }
        return result;
    }
};


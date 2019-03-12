#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = 0;
        if (needle.size() == 0) {
            return result;
        }
        else {
            if (haystack.size() >= needle.size()) {
                int temp = -1;
                for (int i = 0; i < haystack.size()-needle.size()+1; i++) {
                    for (int j = 0; j < needle.size(); j++) {
                        if (haystack[i+j] != needle[j]) {
                            break;
                        }
                        else {
                            temp = j;
                        }
                    }
                    if (temp == needle.size() - 1) {
                        result = i;
                        return result;
                    }
                    else {
                        result = -1;
                    }
                }
            }
            else {
                result = -1;
            }
        }
        return result;
    }
};

int main()
{
    string str1 = "hello";
    string str2 = "ll";
    Solution strS;
    int temp = strS.strStr(str1, str2);
    cout << temp << " \n";
    
}


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty() == true) {
            return 0;
        }
        int pre_flag = false;
        int ptr1 = 0, ptr2 = 0;
        int index = 0;
        while (ptr1 < haystack.size()) {
            if (haystack[ptr1] == needle[ptr2]) {
                if (pre_flag == false) {
                    index = ptr1;    
                }
                ptr1++;
                ptr2++;
                pre_flag = true;                   
            }
            else {
                if (pre_flag == true) {
                    ptr1 = index + 1;
                    ptr2 = 0;
                }
                else {
                    ptr1++;
                }
                pre_flag = false;
            }
            if (ptr2 >= needle.size()) {
                break;
            }
        }
        if (ptr2 >= needle.size()) {
            return index;
        }
        return -1;
        
    }
};


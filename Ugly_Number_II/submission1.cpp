#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglylist(1, 1);
        int index2 = 0, index3 = 0, index5 = 0;
        while (uglylist.size() < n) {
            int num2 = uglylist[index2] * 2;
            int num3 = uglylist[index3] * 3;
            int num5 = uglylist[index5] * 5;
            int num = min(num2, min(num3, num5));
            if (num == num2) {
                index2++;
            }
            if (num == num3) {
                index3++;
            }
            if (num == num5) {
                index5++;
            }
            uglylist.push_back(num);
        }
        return uglylist.back();
    }
};
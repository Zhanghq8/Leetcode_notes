#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> num;
        int temp = n;
        while (temp != 1) {
            int sum = 0;
            while (temp != 0) {
                sum += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            temp = sum;
            if (num.find(temp) != num.end()) {
                break;
            }
            num.insert(temp);
        }
        return temp == 1;
    }
};
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        for (int i=n; i!=0; i=i/2) {
            if (i%2 != 0) {
                result *= x;
            }
            x *= x;
        }
        if (n < 0) {
            result = 1/result;
        }
        return result;
    }
};


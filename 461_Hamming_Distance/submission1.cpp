#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        int XOR = x ^ y;
        for (int i = 0; i < 32; i++) {
            result += (XOR >> i) & 1;
        }
        return result;
    }
};

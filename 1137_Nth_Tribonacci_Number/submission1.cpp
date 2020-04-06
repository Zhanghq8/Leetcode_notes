#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1 || n == 2) {
            return n == 0 ? 0 : 1; 
        }
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};
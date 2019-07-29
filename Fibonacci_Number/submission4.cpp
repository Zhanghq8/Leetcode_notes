#include <iostream>
#include <string>

using namespace std;

// Iterative

class Solution {
public:
    int fib(int N) {
        if (N <= 1) {
            return N;
        }
        int result = 0;
        int temp1 = 0, temp2 = 1;
        for (int i = 2; i<=N; i++) {
            result = temp1 + temp2;
            temp1 = temp2;
            temp2 = result;
        } 
        return result;
    }
};


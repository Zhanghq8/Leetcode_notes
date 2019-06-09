#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i=2; i<n; i++) {
            if (helper(i) == true) {
                count++;
            }
        }
        return count;
    }
private:
    bool helper(int num) {
        for (int i=2; i*i <= num; i++) {
            if (num%i == 0) {
                return false;
            }
        }
        return true;
    }
};


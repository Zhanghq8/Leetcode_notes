#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = left + (right-left)/2;
            cout << mid << endl;
            int result = guess(mid);
            if (result == 0) {
                return mid;
            }
            else if (result == 1) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return x;
        }
        int left = 1;
        int right = x;
        int mid = 0;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (x / mid == mid) {
                return mid;
            }
            else if (x / mid > mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};

int main()
{
    while (true) {
        int value;
        cout << "Enter a non-negative interge value: \n";
        cin>>value;
        Solution test;
        int result = test.mySqrt(value);
        cout << "The sqrt of " << value << " is: " << result << endl;
    }
}

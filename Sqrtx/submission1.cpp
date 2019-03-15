#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int result;
        long low = 0;
        long high = x;
        while (low < high) {
            long mid = (high - low) / 2 + low;
            if (mid * mid == x) {
                result = mid;
                return result;
            }
            else if (mid * mid > x) {
                high = mid - 1;                
            }
            else {
                low = mid + 1;
            }
        }
        if (low * low > x) {
            result = low - 1;
        }
        else {
            result = low;
        }
        return result;
    }
};

int main()
{
    while (true) {
        int value;
        cout << "Enter a non-negative value: \n";
        cin>>value;
        Solution test;
        int result = test.mySqrt(value);
        cout << "The sqrt of " << value << " is: " << result << endl;
    }
}


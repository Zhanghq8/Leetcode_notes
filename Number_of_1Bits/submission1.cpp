#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if (n & 1 == 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};

int main()
{
    uint32_t value = 00000000000000000000000000001011;
    Solution test;
    int result = test.hammingWeight(value);
    cout << "There are " << result << " '1' bits in " << "00000000000000000000000000001011." << endl;
    
}


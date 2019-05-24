#include <iostream>
#include <string>

using namespace std;

// Boyer-Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int count = 0;
        for (auto n:nums) {
            if (count == 0) {
                result = n;
                count++;
            }
            else {
                if (n != result) {
                    count--;
                }
                else {
                    count++;                
                }
            }
        }
        return result;
    }
};
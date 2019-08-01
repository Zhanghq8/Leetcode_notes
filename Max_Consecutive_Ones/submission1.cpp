#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_length = 0;
        int cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
                max_length = max(cnt, max_length);
            }
            else {
                cnt = 0;
            }
        }
        return max_length;
    }
};
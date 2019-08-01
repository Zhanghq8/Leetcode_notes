#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Brute force(TLE)

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                for (int k=j+1; k<nums.size(); k++) {
                    if (nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] && nums[k] + nums[j] > nums[i]) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
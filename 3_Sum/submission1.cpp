#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        if (length < 3 || nums.front() > 0 || nums.back() < 0) {
            return result;
        }
        for (int k=0; k<length-2; k++) {
            if (nums[k] > 0) {
                break;
            }
            if (k > 0 && nums[k] == nums[k-1]) {
                continue;
            }
            int i=k+1; 
            int j=length-1;
            int target = -nums[k];
            while (i<j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(vector<int>{nums[k],nums[i],nums[j]});
                    while (i<j && nums[i]==nums[i+1]) {
                        i++;
                    }
                    while (i<j && nums[j]==nums[j-1]) {
                        j--;
                    }
                    i++;
                    j--;
                }
                else if (nums[i] + nums[j] < target) {
                    i++;
                }
                else {
                    j--;
                }
            }
        }
        return result;
    }
};


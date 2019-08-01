#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        if (nums.size() < 3) {
            return cnt;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            cout << i << endl;
            int k = i + 2;
            for (int j=i+1; j<nums.size()-1 && nums[i] != 0; j++) {
                while (k < nums.size() && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                cnt += k - j - 1;
            }
        }
        return cnt;
    }
};
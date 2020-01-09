#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> data;
        for (int i = 0; i < nums.size(); i++) {
            data.push(nums[i]);
            if (data.size() > k) {
                data.pop();
            }
        }
        return data.top();
    }
};

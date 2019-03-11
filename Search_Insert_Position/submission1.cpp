#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (target <= nums[i]) {
                result = i;
                break;
            }
        }
        if (result == -1) {
            result = nums.size() + 1;
        }
        return result;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    Solution test;
    int result = test.searchInsert(nums, 2);
    cout << result << endl;
}



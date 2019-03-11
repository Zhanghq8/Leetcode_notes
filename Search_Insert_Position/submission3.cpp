//Binary search
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        {
            for (int i = 0; i < nums.size(); i++) {
                if (target <= nums[i]) {
                    return i;
                }
            }
            return nums.size();
        }
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



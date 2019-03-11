//Binary search
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0;
        int mid;
        int tail = nums.size();
        while (head < tail) {
            mid = (head + tail) / 2;
            if (nums[mid] < target) {
                head = mid + 1;
            }
            else {
                tail = mid;
            }
        }
        return head;
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



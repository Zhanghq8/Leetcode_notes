#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size();
        while (i <= j-1) {
            if (nums[i] != val) {
                i++;
            }
            else {
                nums[i] = nums[j-1];
                j--;
            }
        }
        return j;
    }
};

int main()
{   
    int val = 2;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(4);
    nums.push_back(2);
    cout << "After deleting "<< val <<", the original vector [";
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
    Solution test;
    int length = test.removeElement(nums, val);
    cout << "] changed to: [";
    for (int i=0; i<length; i++) {
        cout << nums[i] << " ";
    }
    cout << "].\n";
}


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int index = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[index] != nums[i]) {
                index++;
                nums[index] = nums[i];
            }
        }
        return index+1;
    }
};

int main()
{   
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    cout <<"The array ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    Solution test;
    int result = test.removeDuplicates(nums);
    cout <<"after deletion becomes: ";
    for (int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << ".\n";
}


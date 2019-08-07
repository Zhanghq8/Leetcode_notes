#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        int n = nums.size();
        int mid = (n + 1) / 2 - 1;
        int right = n - 1;
        sort(temp.begin(), temp.end());
        for (int i=0; i<n; i++) {
            if (i % 2 == 0) {
                nums[i] = temp[mid];
                mid--;
            }
            else {
                nums[i] = temp[right];
                right--;
            }            
        }
    }
};
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = array[0];
        int sum = array[0];
        for (int i=1; i<array.size(); i++) {
          sum = max(sum+array[i], array[i]);
          maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};


#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

// Given an unsorted integer array, find the subarray that has the greatest sum. Return the sum and the indices of the left and right boundaries of the subarray. If there are multiple solutions, return the leftmost subarray.

// Assumptions

// The given array is not null and has length of at least 1.
// Examples

// {2, -1, 4, -2, 1}, the largest subarray sum is 2 + (-1) + 4 = 5. The indices of the left and right boundaries are 0 and 2, respectively.

// {-2, -1, -3}, the largest subarray sum is -1. The indices of the left and right boundaries are both 1


// Return the result in a array as [sum, left, right]

class Solution {
public:
    vector<int> largestSum(vector<int>& array) {
        vector<int> result;
        int maxSum = array[0];
        int curSum = array[0];
        int left = 0;
        int right = 0;
        int maxLeft = 0;
        int maxRight = 0;
        for (int i=1; i<array.size(); i++) {
            if (curSum + array[i] > array[i]) {
                curSum += array[i]; 
                right++;
            } else {
                curSum = array[i];
                left = i;
                right = i;
            }
            if (maxSum < curSum) {
                maxSum = curSum;
                maxLeft = left;
                maxRight = right;
            }
        }
        result.push_back(maxSum);
        result.push_back(maxLeft);
        result.push_back(maxRight);
        return result;
    }
};

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int localMax = 0;
        int localMin = 0;
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            localMax = max(A[i], localMax + A[i]);
            localMin = min(A[i], localMin + A[i]);
            maxSum = max(maxSum, localMax);
            minSum = min(minSum, localMin);
            sum += A[i];
        }
        return (sum - minSum == 0) ? maxSum : max(maxSum, sum - minSum);
    }
};
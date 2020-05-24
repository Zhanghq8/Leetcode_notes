#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        int indexA = 0;
        int indexB = 0;
        while (indexA < A.size() && indexB < B.size()) {
            int low = max(A[indexA][0], B[indexB][0]);
            int high = min(A[indexA][1], B[indexB][1]);
            if (low <= high) {
                result.push_back({low, high});
            } 
            if (A[indexA][1] > B[indexB][1]) {
                indexB++;
            } else {
                indexA++;
            }
        }
        return result;
    }
};
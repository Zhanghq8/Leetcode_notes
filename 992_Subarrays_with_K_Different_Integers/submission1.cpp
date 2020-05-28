#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        if (A.empty() || K > A.size()) {
            return 0;
        }
        int left = 0, right = 0;
        int results = 0, result = 1;
        int count = 0;
        vector<int> hash(A.size() + 1, 0);
        for (; right < A.size(); right++) {
            hash[A[right]]++;
            if (hash[A[right]] == 1) {
                count++;
            }
            while (count > K || hash[A[left]] > 1) {
                if (count > K) {
                    result = 1;
                    count--;
                } else {
                    result++;
                }
                hash[A[left]]--;
                left++;
            }
            if (count == K) {
                results += result;
            }
        }
        return results;
    }
};
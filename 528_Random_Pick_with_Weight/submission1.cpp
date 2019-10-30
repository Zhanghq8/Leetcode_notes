#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    Solution(vector<int>& w) {
        sum = w;
        for (int i=1; i<w.size(); i++) {
            sum[i] = sum[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int num = rand() % sum.back();
        int left = 0, right = sum.size();
        while (left < right) {
            int mid = left + (right-left)/2;
            if (sum[mid] <= num) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
private:
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
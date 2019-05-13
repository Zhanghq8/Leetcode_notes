#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0; 
        }
        int length = nums.size();
        vector<int> dp(length);
        dp[0] = nums[0];
        int max_sum = dp[0];
        for (int i=1; i<nums.size(); i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            max_sum = max(max_sum, dp[i]);
        }
        return max_sum;
    }
};

int main()
{
    vector<int> data;
    data.push_back(-2);
    data.push_back(1);
    data.push_back(-3);
    data.push_back(4);
    data.push_back(-1);
    data.push_back(2);
    data.push_back(1);
    data.push_back(-5);
    data.push_back(4);
    cout << "The input vector are: [ " ;
    for (int i=0; i<data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << "]. " << endl;
    int result;
    Solution test;
    result = test.maxSubArray(data);
    cout << "You can get " << result << " max contiguously." << endl;
}



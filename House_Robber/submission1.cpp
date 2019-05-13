#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        if (length == 1) {
            return nums[0];
        }
        if (length == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(length);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i=2; i<length; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[length-1];
    }
};

int main()
{
    vector<int> data;
    data.push_back(2);
    data.push_back(7);
    data.push_back(9);
    data.push_back(3);
    data.push_back(1);
    cout << "The input vector are: [ " ;
    for (int i=0; i<data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << "]. " << endl;
    int result;
    Solution test;
    result = test.rob(data);
    cout << "You can get " << result << " max." << endl;

}


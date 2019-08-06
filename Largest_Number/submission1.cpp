#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a); 
        });
        string result = "";
        for (int i=0; i<nums.size(); i++) {
            result += to_string(nums[i]);
        }
        if (result[0] == '0') {
            return "0";
        }
        return result;
    }
};
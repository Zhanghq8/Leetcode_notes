// Bubble sort
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        stack<int> vec;
        for (int k = 0; k < nums.size(); k++) {
            if (vec.empty() == true) {
                vec.push(nums[k]);
            }
            else {
                if (vec.top() == nums[k]) {
                    vec.pop();
                }
                else {
                    return vec.top();
                }
            }
        }
        return vec.top();
    }
};

int main()
{   
    Solution temp;
    vector<int> test;
    test.push_back(4);
    test.push_back(2);
    test.push_back(1);
    test.push_back(2);
    test.push_back(1);
    int result = temp.singleNumber(test);
    cout << "The single number is: " << result << endl;
}


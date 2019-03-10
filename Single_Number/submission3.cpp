// Insertion sort
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            int value = nums[i];
            int index = i;
            while (index > 0 && nums[index-1] > value) {
                nums[index] = nums[index-1];
                index -= 1;
            }
            nums[index] = value;
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


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i=0; i<nums.size()-1; i++)
        {
            for (int j=0; j<nums.size(); j++)
            {
                if (j>i && nums[j] == target - nums[i])
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> test;
    test.push_back(2);
    test.push_back(7);
    test.push_back(11);
    test.push_back(5);
    int target = 9;
    vector<int> index;
    Solution temp;
    index = temp.twoSum(test, target);
    cout << "The index vector is: ";
    for (int i = 0; i < index.size(); i++)
    {
        cout << index[i] << " ";
    }
    cout << "" << endl;
}


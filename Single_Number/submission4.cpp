// bit operation XOR
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i]; 
        }
        return result;
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


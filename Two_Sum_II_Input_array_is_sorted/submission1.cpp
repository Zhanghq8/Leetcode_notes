#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() == 0) {
            return vector<int>();
        }
        vector<int> result;
        int head_index = 0;
        int tail_index = numbers.size()-1;
        while (head_index<tail_index) {
            if (numbers[head_index] + numbers[tail_index] == target) {
                result.push_back(head_index+1);
                result.push_back(tail_index+1);
                return result;
            }
            else if (numbers[head_index] + numbers[tail_index] > target) {
                tail_index--;
            }
            else {
                head_index++;
            }
        }
        return result;
    }
};

int main()
{   
    int target = 9;
    vector<int> data;
    data.push_back(2);
    data.push_back(7);
    data.push_back(11);
    data.push_back(15);

    cout << "The input vector is: [ ";
    for (int i=0; i<data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << "]. And the target is: " << target << "." << endl;

    Solution test;
    vector<int> result = test.twoSum(data, target);
    cout << "The index vector is : [ ";
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "]." << endl;

}
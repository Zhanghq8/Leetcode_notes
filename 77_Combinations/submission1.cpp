#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> output;
        addsolution(n, k, 1, output, result);
        return result;
    }
private:
    void addsolution(int max_num, int num, int start, vector<int>& output, vector<vector<int>>& result) {
        if (output.size() == num) {
            result.push_back(output);
            return;
        }
        for (int i=start; i<=max_num; i++) {
            output.push_back(i);
            addsolution(max_num, num, i+1, output, result);
            output.pop_back();
        }
    }
};


// Recursion tree
//                    []
//             /    |    |    \
//            1     2    3     4
//           /|\   /\    |      
//          2 3 4 3  4   4
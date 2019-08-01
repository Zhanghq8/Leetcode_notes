#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int ori_row, ori_col;
        ori_row = nums.size();
        ori_col = nums[0].size();
        if (ori_row * ori_col != r * c) {
            return nums;
        }
        vector<vector<int>> new_nums(r, vector<int> (c, 0));
        for (int i=0; i<new_nums.size(); i++) {
            for (int j=0; j<new_nums[i].size(); j++) {
                int index = i * c + j;
                int r_temp=-1, c_temp=-1;
                if (i + j == 0) {
                    r_temp = 0;
                    c_temp = 0;
                }
                else {               
                    if (index % ori_col == 0) {
                        r_temp = index/ori_col;
                        c_temp = 0;
                    }
                    else {
                        r_temp = index/ori_col;
                        c_temp = index % ori_col;
                    }
                }
                new_nums[i][j] = nums[r_temp][c_temp]; 
            }
        }
        return new_nums;
    }
};
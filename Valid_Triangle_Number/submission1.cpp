#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Recursive(TLE)

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        vector<int> triangles;
        int num = 3;
        helper(nums, triangles, 3, 0);
        return cnt;
    }
private:
    int cnt = 0;
    void helper(vector<int>& nums, vector<int>& triangles, int num, int start) {
        if (triangles.size() == num) {
            int a, b, c;
            a = triangles[0];
            b = triangles[1];
            c = triangles[2];
            if (a+b>c && a+c>b && b+c>a) {
                cnt++;
            }
            return;
        }
        for (int i=start; i<nums.size(); i++) {
            triangles.push_back(nums[i]);
            helper(nums, triangles, num, i+1);
            triangles.pop_back();
        }
    }
};
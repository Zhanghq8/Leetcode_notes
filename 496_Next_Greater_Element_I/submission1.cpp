#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> next;
        stack<int> S;
        for (auto num : nums2) {
            while (!S.empty() && num > S.top()) {
                next[S.top()] = num;
                S.pop();
            }
            S.push(num);
        }
        for (auto num : nums1) {
            result.push_back(next.count(num) ? next[num] : -1);
        }
        return result;
    }
};


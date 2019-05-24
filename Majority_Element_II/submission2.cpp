#include <iostream>
#include <string>

using namespace std;

// Boyer-Moore Majority Vote algorithm
// We can only get two votes numbers using BM algorithm, then we verify if these two numbers meet the requirement.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m_ele1 = 0;
        int m_ele2 = 0;
        int count1 = 0;
        int count2 = 0;
        vector<int> result;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == m_ele1) {
                count1++;
            }
            else if (nums[i] == m_ele2) {
                count2++;
            }
            else if (nums[i] != m_ele1 && count1 == 0) {
                count1++;
                m_ele1 = nums[i];
            }
            else if (nums[i] != m_ele2 && count2 == 0) {
                count2++;
                m_ele2 = nums[i];
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == m_ele1) {
                count1++;
            }
            else if (nums[i] == m_ele2) {
                count2++;
            }
        }
        if (count1 > nums.size()/3) {
            result.push_back(m_ele1);
        }
        if (count2 > nums.size()/3) {
            result.push_back(m_ele2);
        }
        return result;
    }

};

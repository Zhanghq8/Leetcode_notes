#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int i=0; i<nums1.size(); i++) {
            int count = 0;
            int max = INT_MIN;
            for (int j=0; j<nums2.size(); j++) {
                if (nums2[j] == nums1[i] && j != nums2.size()-1) {
                    max = nums1[i];
                    count = 1;
                }
                if (max == nums1[i] && j == nums2.size()-1) {
                    if (nums2[j] < max) {
                        result.push_back(-1);
                    }
                }
                if (nums2[j] == nums1[i] && j == nums2.size()-1) {
                    result.push_back(-1);
                }
                else if (nums2[j] > nums1[i] && count == 1) {
                    result.push_back(nums2[j]);
                    max = nums2[j];
                    count = 2;
                }
            }
            count = 0;
        }
        return result;
    }
};

int main()
{
    vector<int> nums1, nums2;
    nums1.push_back(4);
    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(2);

    cout << "Nums1(subset of nums2): [ ";
    for (int i=0; i<nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << "]." << endl;

    cout << "Nums2: [ ";
    for (int i=0; i<nums2.size(); i++) {
        cout << nums2[i] << " ";
    }
    cout << "]." <<endl;

    Solution test;
    vector<int> result = test.nextGreaterElement(nums1, nums2);
    cout << "The output: [ ";
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "]." <<endl;
}


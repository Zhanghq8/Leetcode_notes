#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        for (int i = 0; i < m; i++) {
            temp.push_back(nums1[i]);
        }
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < m && j < n) {
            if (temp[i] < nums2[j]) {
                nums1[k] = temp[i];
                i += 1;
            }
            else {
                nums1[k] = nums2[j];
                j += 1;
            }
            k += 1;
        }
        while (i < m) {
            nums1[k] = temp[i];
            i++;
            k++;
        }
        while (j < n) {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};
int main()
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);

    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);
    int m = 3;
    int n = 3;
    Solution test;
    test.merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << "\n";
}


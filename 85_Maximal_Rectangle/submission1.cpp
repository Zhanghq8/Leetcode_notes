#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int globalMax = 0;
        vector<int> histogram(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') {
                    histogram[j] = 0;
                } else {
                    histogram[j] += 1;
                }
            }
            int temp = maxHistogram(histogram);
            globalMax = max(globalMax, temp);
        }
        return globalMax;
    }
private:
    int maxHistogram(vector<int>& histogram) {
        int maxArea = 0;
        stack<int> index;
        histogram.push_back(0);
        for (int i = 0; i < histogram.size(); i++) {
            int area = 0;
            while (!index.empty() && histogram[i] <= histogram[index.top()]) {
                int top = index.top();
                index.pop();
                if (index.empty()) {
                    area = histogram[top] * i; 
                } else {
                    area = histogram[top] * (i - index.top() - 1);
                }
                maxArea = max(area, maxArea);
            }
            index.push(i);
        }
        return maxArea;
    }
};
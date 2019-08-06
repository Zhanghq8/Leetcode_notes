#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int result;
        priority_queue<int> pq; 
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                pq.push(matrix[i][j]);
            }
        }
        while (matrix.size() * matrix.size() - k > 0) {
            pq.pop();
            k++;
        }
        result = pq.top();
        return result;
        
    }
};
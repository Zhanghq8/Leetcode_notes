#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        for (int i=0; i<numRows; i++) {
            vector<int> temp;
            for (int j=0; j<i+1; j++) {
                temp.push_back(1);
            }
            result.push_back(temp);
        }
        for (int i=2; i<numRows; i++) {
            for (int j=1; j<i; j++) {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        return result;
    }
};

int main()
{   
    Solution test;
    vector<vector<int> > result = test.generate(5);
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << " \n";
    }
    cout << " \n";
}


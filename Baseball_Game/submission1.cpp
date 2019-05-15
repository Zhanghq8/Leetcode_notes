#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        if (ops.size() == 0) {
            return 0;
        }
        int result = 0;
        stack<int> valid;
        for (int i=0; i<ops.size(); i++) {
            if (ops[i] == "C") {
                result -= valid.top();
                valid.pop();
            }
            else if (ops[i] == "D") {
                int temp = 2*valid.top();
                valid.push(temp);
                result += temp;
            }
            else if (ops[i] == "+") {
                int temp1, temp2;
                temp1 = valid.top();
                valid.pop();
                temp2 = temp1 + valid.top();
                valid.push(temp1);
                valid.push(temp2);
                result += temp2;     
            }
            else {
                valid.push(stoi(ops[i]));
                result += stoi(ops[i]);
            }
        }
        return result;
    }
};

int main()
{
    vector<string> data;
    data.push_back("5");
    data.push_back("-2");
    data.push_back("4");
    data.push_back("C");
    data.push_back("D");
    data.push_back("9");
    data.push_back("+");
    data.push_back("+");

    cout << "The operations you entered are: [ ";
    for (int i=0; i<data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << "]. " << endl;
    Solution test;
    int result = test.calPoints(data);
    cout << "And the final points you get is: " << result << "." << endl;
}

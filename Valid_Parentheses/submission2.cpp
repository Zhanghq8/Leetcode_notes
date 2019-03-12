#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> temp; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                temp.push_back(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (temp.empty() == true || (*temp.end() != '(' && s[i] == ')') || (*temp.end() != '[' && s[i] == ']') || (*temp.end() != '{' && s[i] == '}')) {
                    return false;
                }
                else {
                    temp.pop_back();
                }
            }
        }
        return temp.empty() ? true:false;
    }
};

int main()
{

    Solution temp;
    string str;
    while (1) {
        cout << "Enter the string you want to test: \n";
        cin >> str;
        bool result = temp.isValid(str);
        if (result == true) {
            cout << str << " is valid" << endl;
        }
        else {
            cout << str << " is not valid" << endl;
        }
    }
}
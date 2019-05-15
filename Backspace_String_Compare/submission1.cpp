#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        if (S.size() == 0 && T.size() == 0){
            return true;
        }
        stack<char> S_element;
        stack<char> T_element;
        for (int i=0; i<S.size(); i++) {
            if (S[i] !='#') {
                S_element.push(S[i]);
            }
            else if (S_element.size() != 0 && S[i] == '#') {
                S_element.pop();
            }
        }
        for (int i=0; i<T.size(); i++) {
            if (T[i] !='#') {
                T_element.push(T[i]);
            }
            else if (T_element.size() != 0 && T[i] == '#') {
                T_element.pop();
            }
        }
        if (S_element.size() != T_element.size()) {
            return false;
        }
        else {
            int length = S_element.size();
            while (length>0) {
                if (S_element.top() != T_element.top()) {
                    return false;
                }
                else {
                    S_element.pop();
                    T_element.pop();
                    length--;
                }
            }
        }
        return true;
    }
};

int main()
{   
    string S = "ab##";
    string T = "c#d#";
    cout << "S string is: " << S << endl;
    cout << "T string is: " << T << endl;

    Solution test;
    bool result = test.backspaceCompare(S, T);
    if (result == true) {
        cout << "S and T string are equal." << endl;
    }
    else{
        cout << "S and T string are not equal." << endl;
    }
}

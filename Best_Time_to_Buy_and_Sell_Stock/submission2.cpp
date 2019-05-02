#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int i=0; i<prices.size(); i++)
        {
            for (int j=i+1; j<prices.size(); j++)
            {
                if (prices[j]-prices[i] > max_profit)
                max_profit = prices[j]-prices[i];
            }
        }
        return max_profit;
    }
};

int main()
{   
    vector<int> stock_price;
    stock_price.push_back(7);
    stock_price.push_back(1);
    stock_price.push_back(5);
    stock_price.push_back(3);
    stock_price.push_back(6);
    stock_price.push_back(4);

    Solution test;
    cout << "The price on each day is: ";
    int result = test.maxProfit(stock_price);
    for (int i=0; i<stock_price.size(); i++)
    {
        cout << stock_price[i] << " ";
    }
    cout << "." << endl;
    cout << "And the maximum profit you can get is: " << result << ".\n"; 
}


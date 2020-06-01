Question : Say you have an array prices for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

//c++ soln

class Solution {
public:
    int maxhelp(vector<int>& price,int n){
       int pr=0,i=0;
    
    while (i < n - 1) { 
  
        while ((i < n - 1) && (price[i + 1] <= price[i])) 
            i++; 
        if (i == n - 1) 
            break; 
        int buy = i++; 
  
        while ((i < n) && (price[i] >= price[i - 1])) 
            i++; 
        int sell = i - 1; 
        pr=price[sell]-price[buy]+pr;
    } 
        return pr;
    }
    int maxProfit(vector<int>& prices) {
        int c=maxhelp(prices,prices.size());
        return c;
    }
};

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> stk;
    int ind;
    StockSpanner() {
        stk=stack<pair<int,int>>();
        ind=0;
    }
    
    int next(int price) {
        while(!stk.empty() && stk.top().first<=price ){
            stk.pop();
        }
        ind++;
        cout<<ind<<"\n";
        int ans=(stk.empty()==true ? ind : ind - stk.top().second);
        stk.push({price , ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
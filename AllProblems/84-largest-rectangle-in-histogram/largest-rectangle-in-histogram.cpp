#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
    vector<int> nextSmaller(vector<int>& heights , int n){
        vector<int> ans(n , n);
        stack<int> stk;

        for(int i=n-1 ; i>=0 ; i--){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }

            if(!stk.empty()){
                ans[i]=stk.top();
            }

            stk.push(i);
        }

        return ans;
    }

    vector<int> previousSmaller(vector<int>& heights , int n ){

        vector<int> ans(n , -1);
        stack<int> stk;
        
        for(int i=0 ; i<n ; i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }

            if(!stk.empty()){
                ans[i]=stk.top();
            }

            stk.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        // way 1 to store the indice of next smaller and previous smaller for each index in a array . using monotonic stack .
        // using them comute the maximum array possible for a particular height at a particular bar on a histogram
        // equation is (nse[i]-pse[i]-1)*heights[i];

        int n=heights.size();
        vector<int> nse=nextSmaller(heights , n),pse=previousSmaller(heights , n);

        int ans=0;
        for(int i=0 ; i<n ; i++){
            ans=max(ans , heights[i]*(nse[i]-pse[i]-1));
        }

        return ans;
    }
};
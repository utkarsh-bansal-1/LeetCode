#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    vector<int> previousSmallerElementId(vector<int>& arr , int n ){
        stack<int> stk;
        vector<int> ans(n , -1);
        for(int i=0 ; i<n ; i++){
            while(!stk.empty() && arr[stk.top()]>arr[i]){
                stk.pop();
            }

            if(!stk.empty()){
                ans[i]=stk.top();
            }

            stk.push(i);
        }

        return ans;
    }

    vector<int> nextSmallerElementId(vector<int> arr , int n ){
        stack<int> stk;
        vector<int> ans(n , n);
        for(int i=n-1 ; i>=0 ; i--){
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
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
    int sumSubarrayMins(vector<int>& arr) {
        // next greater and next smaller elements index . 
        // to solve this it is pretty simple we are gonna find the nse and the nge matrix . and then using it 
        // use simple math to calculate final result . 

        //sum of subarray minimums . 
        // sum of subarray largest . will think about it later on . 

        // here lets write the value of the next largest and the next smallest element index code . 
        int MOD=1e9+7;
        int n=arr.size();
        vector<int> pge=previousSmallerElementId(arr , n),nge=nextSmallerElementId(arr , n);
        long long ans=0;
        for(int i=0 ; i<n ; i++){
            ans=(ans + 1ll*arr[i]*(i-pge[i])*(nge[i]-i)%MOD)%MOD;
        }

        return (int)ans;
    }
};
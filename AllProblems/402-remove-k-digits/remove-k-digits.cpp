#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        // insert into stack . whenever current element to be inserted is less than the topmost elements 
        // ex . 4 5 6 now we want to insert 1 . so we will keep removing from 4 5 6 as first 6 then 5 then 4 to get 1 only . this way we get the least number on top . 1 2 7 3 .

        stack<char> stk;
        int n=num.size();
        for(int i=0 ; i<n ; i++){
            while(!stk.empty() && k>0 && (stk.top()-'0')>(num[i]-'0')){
                k--;
                stk.pop();
            }

            stk.push(num[i]);
        }

        while(k>0){
            stk.pop();
            k--;
        }

        // then ideally we found the minimum possible stack . then we have to make the minimum possible string . 
        string ans="";
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }

        // now we have the string in reverse order . 
        reverse(ans.begin() , ans.end());

        //now remove the leading zeros . 
        string ans1="";
        n=ans.size();
        int i=0;
        while(i<n && ans[i]=='0'){
            i++;
        }

        while(i<n){
            ans1+=ans[i];
            i++;
        }


        // now handle the edge cases . 

        if(ans1==""){
            return "0";
        }
        return ans1;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool isPalindrome(string& s){
        int n=s.size();
        for(int i=0 ; i<n/2 ; i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }

    void recPartition(int idx , int n , vector<string>& part , vector<vector<string>>& ans , string& s ){
        if(idx==n){
            ans.push_back(part);
            return;
        }

        for(int i=idx ; i<n ; i++){
            string subStr=s.substr(idx , i- idx+1);
            if(isPalindrome(subStr)){
                part.push_back(subStr);
                recPartition(i+1 , n , part ,ans , s );
                part.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> part;
        vector<vector<string>> ans;

        recPartition(0 , n , part ,  ans , s);

        return ans;
    }
};
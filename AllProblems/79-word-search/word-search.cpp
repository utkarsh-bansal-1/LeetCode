#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int,int>> dir={{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};

    private:
    bool recFind(string& s , string& word , int i , int j , set<pair<int,int>>& sSet , int sSize , int wordSize ,vector<vector<char>>& board , int n , int m  ){
        if(s==word){
            return true;
        }

        if(i>=n || j>=m || j<0 || i<0 || sSet.find({i , j})!=sSet.end()){
            return false;
        }

        if(board[i][j]!=word[sSize]){
            return false;
        }

        // try all possible directions after adding current charachter . 
        s.push_back(board[i][j]);
        sSet.insert({i , j});
        for(auto pr : dir){
            if(recFind(s , word , i+pr.first , j+pr.second , sSet , sSize+1 , wordSize , board ,n , m )){
                return true;
            };
        }
        sSet.erase({i , j});
        s.pop_back();

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        string s="";
        int n=board.size();
        int m=board[0].size();
        set<pair<int,int>> sSet;
        int wordSize=word.size();

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(recFind( s,  word , i  , j , sSet , 0 , wordSize , board , n , m  )){
                    return true;
                }
            }
        }

        return false;
    }
};
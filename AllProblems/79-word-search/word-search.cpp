#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int,int>> dir={{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};

    private:
    bool recFind( string& word , int i , int j , int sSize , int wordSize ,vector<vector<char>>& board , int n , int m  ){
        if(sSize==wordSize){
            return true;
        }

        if(i>=n || j>=m || j<0 || i<0 ){
            return false;
        }

        if(board[i][j]!=word[sSize]){
            return false;
        }


        // try all possible directions after adding current charachter . 
        char temp=board[i][j];
        board[i][j]='#';

        for(auto pr : dir){
            if(recFind( word , i+pr.first , j+pr.second ,  sSize+1 , wordSize , board ,n , m )){
                return true;
            };
        }

        board[i][j]=temp;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int wordSize=word.size();

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(recFind( word , i  , j , 0 , wordSize , board , n , m  )){
                    return true;
                }
            }
        }

        return false;
    }
};
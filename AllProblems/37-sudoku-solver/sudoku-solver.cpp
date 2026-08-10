#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool recSolveSudoku(int row , int column ,  vector<vector<char>>& board , vector<vector<bool>>& rows , vector<vector<bool>>& columns , vector<vector<bool>>& boxes ){
        if(row==9){
            return true;
        }

        if(column==9){
            return recSolveSudoku(row+1 , 0 , board , rows,  columns , boxes );
        }

        //travel from 0 to n-1 . and check if we have '.'
        if(board[row][column]=='.'){
            for(int dig=1 ; dig<10 ; dig++){
                if(rows[row][dig]==false && columns[column][dig]==false && boxes[(row/3)*3+(column/3)][dig]==false){

                    rows[row][dig]=true;
                    columns[column][dig]=true;
                    boxes[(row/3)*3+(column/3)][dig]=true;
                    board[row][column]='0'+dig;

                    bool ans=recSolveSudoku(row , column+1 , board , rows , columns , boxes);

                    if(ans==true){
                        return true;
                    }
                    
                    board[row][column]='.';
                    rows[row][dig]=false;
                    columns[column][dig]=false;
                    boxes[(row/3)*3+(column/3)][dig]=false;
                }
            }
            return false;
        }

        return recSolveSudoku(row , column+1 , board , rows ,columns , boxes);
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9 , vector<bool>(10, false)),columns(9 , vector<bool>(10 , false)),boxes(9 , vector<bool>(10 , false));
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(board[i][j]!='.'){
                    int dig=board[i][j]-'0';
                    rows[i][dig]=true;
                    columns[j][dig]=true;
                    boxes[(i/3)*3+(j/3)][dig]=true;
                }
            }
        }

        bool ans=recSolveSudoku(0 , 0 , board , rows , columns , boxes);
    }
};
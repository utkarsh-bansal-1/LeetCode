#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void recCombinationSum(int sum , int target , vector<vector<int>>& ans , vector<int>& subseq ,int idx , int n , vector<int>& candidates ){
        if(sum==target){
            ans.push_back(subseq);
            return;
        }

        if(idx==n || sum>target){
            return;
        }

        // take the curr ele in sub seq . 
        subseq.push_back(candidates[idx]);
        recCombinationSum(sum+candidates[idx] , target , ans , subseq , idx , n , candidates);
        subseq.pop_back();

        //not take cases . 
        recCombinationSum(sum , target , ans , subseq , idx+1 , n , candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> subseq;
        recCombinationSum(0 , target ,ans , subseq ,0 , n , candidates );

        return ans;
    }
};
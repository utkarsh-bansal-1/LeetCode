#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>  subsets;
        for(int mask=0 ; mask<(1<<(n)) ; mask++){
            vector<int> subset;
            for(int i=0 ; i<n ; i++){
                if((mask&(1<<i))!=0){
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};
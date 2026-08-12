class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n , -1);
        stack<int> stk;
        int i=2*n-1;
        while(i>=0){
            while(!stk.empty() && stk.top()<=nums[i%n]){
                stk.pop();
            }
            if(i<n && !stk.empty()){
                ans[i]=stk.top();
            }
            stk.push(nums[i%n]);
            i--;
        }
        return ans;
    }
};
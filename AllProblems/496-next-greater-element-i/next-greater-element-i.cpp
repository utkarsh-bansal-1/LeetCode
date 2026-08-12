class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();

        // step 1 . index to value mapping . 
        unordered_map<int,int> mpp(n2);
        for(int i=0 ; i<n2 ; i++){
            mpp[nums2[i]]=i;
        }

        // step 2 . index to ans mapping . 
        vector<int> ans1(n2 , -1);
        stack<int> stk;
        for(int i=n2-1 ; i>=0 ; i--){
            int currVal=nums2[i];
            if(!stk.empty() && currVal<stk.top()){
                ans1[i]=stk.top();
                stk.push(currVal);
            }
            else{
                while(!stk.empty() && currVal>stk.top()){
                    stk.pop();
                }

                if(!stk.empty()){
                    ans1[i]=stk.top();
                }

                stk.push(currVal);
            }
        }

        // step 3 value to ans mapping . 
        vector<int> ans2(n1);
        for(int i=0 ; i<n1 ; i++){
            ans2[i]=ans1[mpp[nums1[i]]];
        }

        return ans2;
    }
};
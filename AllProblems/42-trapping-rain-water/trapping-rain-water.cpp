class Solution {
public:
    int trap(vector<int>& height) {
        // better approach using two stacks prefix and suffix . ans [i]= min(prefix , suffix ) -  height[i] . 
        // prefix or suffix have values representing the maximum found height till that index . including that index . 
        int n=height.size();
        vector<int> prefix(n , 0),suffix(n , 0);
        int maxele=0;
        for(int i=0 ; i<n ; i++){
            maxele=max(maxele , height[i]);
            prefix[i]=maxele;
        }

        maxele=0;
        for(int i=n-1 ; i>=0 ; i--){
            maxele=max(maxele, height[i]);
            suffix[i]=maxele;
        }

        int ans=0;
        for(int i=0 ; i<n ; i++){
            ans+=min(prefix[i] , suffix[i])-height[i];
        }

        return ans;
    }
};
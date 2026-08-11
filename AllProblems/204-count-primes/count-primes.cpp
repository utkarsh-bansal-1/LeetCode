class Solution {
public:
    int countPrimes(int n) {
       // to do that . where n belongs to less than or equal to 5*10^6 . we follow seive of erathnosis . 
        vector<int> seive(n, true);
        int ans=0;
        for(int i=2 ; i<n ; i++){
            if(seive[i]){
                for(long j=1ll*i*i ; j<n ; j+=i){
                    seive[j]=false;
                }
                ans++;
            }
        } 
        
        return ans;
    }
};
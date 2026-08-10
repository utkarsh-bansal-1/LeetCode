class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr=start^goal;
        int cnt=0;
        while(xorr>0){
            cnt++;
            xorr=(xorr)&(xorr-1);
        }
        return cnt;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }

        return ((n&(0LL+n-1))==0);
    }
};
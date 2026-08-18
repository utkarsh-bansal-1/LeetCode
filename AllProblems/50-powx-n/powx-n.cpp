class Solution {
    private: 
    double recPow(double x , int n){
        if(n==0){
            return 1;
        }

        double halfPow=recPow(x , n/2);

        if(n%2==0){
            return halfPow*halfPow;
        }
        return halfPow*halfPow*x;

    }
public:
    double myPow(double x, int n) {
        if(n<0){
            return recPow( 1/x , -1*1LL*n);
        }
        return recPow( x , n);
    }
};
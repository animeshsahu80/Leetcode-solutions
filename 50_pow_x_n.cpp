class Solution {
public:
    
    double positive(double x,int n){
        if(n==0)
            return 1;
    double smallout=positive(x,n/2);
    if(n%2==0)
        return smallout* smallout;
    else
        return x*smallout*smallout;
    }
    double negative(double x,int n){
        if(n==-1)
            return 1/x;
    double smallout=negative(x,n/2);
    if(n%2==0)
        return smallout*smallout;
    else
        return smallout*smallout*(1/x);
    }
    double myPow(double x, int n) {
        if(n>=0)
            return positive(x,n);
        else
            return negative(x,n);
    }
};
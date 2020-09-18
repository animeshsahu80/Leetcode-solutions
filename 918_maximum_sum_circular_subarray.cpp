class Solution {
public:
    int kdane(vector<int> vec){
        int max_here=0;
        int max_so_far=0;
        for(int i=0;i<vec.size();i++){
            max_here+= vec[i];
            if(max_so_far<max_here)
                max_so_far=max_here;
            if(max_here<0)
                max_here=0;
        }
        return max_so_far;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int max1=kdane(A);
        int  sum=0;
        int flag=false;
        for(int i=0;i<A.size();i++){
            if(A[i]>=0)
                flag=true;
            sum+=A[i];
            A[i]=-1*A[i];
        }
        if(flag==false){
            int ret=INT_MAX;
            for(auto num:A){
                ret=min(ret,num);
            }
            return -1*ret;
        }
            
        int max2=kdane(A);
        int real_max=sum- (-1)*max2;
         
        int ans=max(real_max,max1);
        
        return ans;
    }
};
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(citations[m]==n-m)
                return n-m;
            if(n-m>citations[m]){
                l=m+1;
            }
            else
                h=m-1;
        }
        return n-l;
    }
};
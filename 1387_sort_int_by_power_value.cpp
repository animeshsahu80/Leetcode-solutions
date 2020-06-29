
 bool cmp(const pair<int,int>&a,const pair<int,int>&b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        else
        return a.second< b.second;
    }
    
class Solution {
public:
    
   
    int solve(int num){
        int count=0;
        while(num!=1){
            if(num%2==0){
                num=num/2;
            }
            else{
                num=num*3 +1;
            }
            count++;
        }
        return count;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> res;
        for(int i=lo ;i <=hi;i++){
            int temp=solve(i);
            res.push_back(make_pair(i,temp));
        }
        sort(res.begin(),res.end(),cmp);
        return res[k-1].first;
    }
};
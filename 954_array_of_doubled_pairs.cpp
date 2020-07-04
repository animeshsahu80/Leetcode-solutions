class Solution {
public:
   static bool comp(const int& a,const int& b){
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int>& A) {
     
        map<int,int> mp;
        for(auto i:A){
            if(mp.find(i)==mp.end()){
                mp[i]=1;
            }
            else{
                mp[i]++;
            }
        }
        sort(A.begin(),A.end(),comp);
        for(auto i:A){
            if(mp[i]>0){
                if(mp[2*i]>0){
                    mp[i]--;
                    mp[2*i]--;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int find(int val,vector<int>& parent){
        if(parent[val]==-1)
            return val;
        parent[val]=find(parent[val],parent);
        return parent[val];
    }
    
    void Union(int a,int b,vector<int>& parent){
        int par_a=find(a,parent);
        int par_b=find(b,parent);
        if(par_a!=par_b){
            parent[par_b]=par_a;
        }
    }
    int largestComponentSize(vector<int>& A) {
        vector<int> parent(100001,-1);
        int n=A.size();
        for(int i=0;i<A.size();i++){
            int num=A[i];
            for(int k=2;k<=sqrt(num);k++){
                if(num%k==0){
                    Union(num,k,parent);
                    Union(num,num/k,parent);
                }
            }
        }
        int count=1;
        map<int,int> mp;
        for(int i=0;i<A.size();i++){
            int par=find(A[i],parent);
            mp[par]++;
            count=max(count,mp[par]);
        }
        return count;
    }
};
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>> adj(n,vector<int>(n,100000));
       for(int i=0;i<n;i++){
           adj[i][i]=0;
       }
       for(int i=0;i<edges.size();i++){
           int p=edges[i][0];
           int q=edges[i][1];
           int wt=edges[i][2];
           adj[p][q]=wt;
           adj[q][p]=wt;
       }
       for(int k=0;k<n;k++){
           for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
               }
           }
       }
        int max_val=n;
        int th=n;
        int min_city=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j&&adj[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=max_val){
                max_val=count;
                min_city=i;
            }
        }
        return min_city;
    }
};
class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int newc,int old){
        if(sr<0 || sr>=image.size() || sc <0 || sc>=image[0].size() || image[sr][sc]!=old)
            return ;
        image[sr][sc]=newc;
        dfs(image,sr+1,sc,newc,old);
        dfs(image,sr,sc+1,newc,old);
        dfs(image,sr-1,sc,newc,old);
        dfs(image,sr,sc-1,newc,old);
        return;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc])
            return image;
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};
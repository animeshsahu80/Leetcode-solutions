class Solution {
public:
    vector<int> calc(int num,int r){
        int x=(num-1)/r;
        int y=(num-1)%r;
        if(x%2==1)
            y=r-y-1;
        x=r-1-x;
        return {x,y};
        
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int r=board.size();
        queue<int> q;
        q.push(1);
        int step=0;
        while(q.size()>0){
            int n=q.size();
            while(n--){
                int num=q.front();
                q.pop();
                if(num==r*r)
                    return step;
                
                for(int i=1;i<=6;i++){
                    int next_step=num+i;
                    if(next_step>r*r)
                        break;
                    vector <int> v=calc(next_step,r);
                    int x=v[0];
                    int y=v[1];
                    if(board[x][y]!=-1){
                        next_step=board[x][y];
                    }
                    if(board[x][y]!=INT_MAX){
                        q.push(next_step);
                        board[x][y]=INT_MAX;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
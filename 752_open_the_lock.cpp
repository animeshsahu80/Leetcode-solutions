class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for(auto st:deadends){
            dead.insert(st);
        }
        if(dead.count("0000"))
            return -1;
        unordered_set<string> visited;
        string s="0000";
        visited.insert(s);
        queue<string> q;
        q.push(s);
        int level=0;
        while(q.size()){
            int n=q.size();
            level++;
            while(n--){
                string temp=q.front();
                q.pop();
                if(temp==target)
                    return level-1;
                for(int i=0;i<4;i++){
                    string str=temp;
                    int digit=str[i]-'0';
                    digit++;
                    digit=digit%10;
                    str[i]=digit+'0';
                    if(visited.count(str)==0 && dead.count(str)==0){
                        q.push(str);
                        visited.insert(str);
                    }  
                }
                for(int i=0;i<4;i++){
                    string str=temp;
                    int digit=str[i]-'0';
                    digit--;
                    if(digit<0)
                        digit=9;
                    str[i]=digit+ '0';
                     if(visited.count(str)==0 && dead.count(str)==0){
                        q.push(str);
                        visited.insert(str);
                    } 
                }
            }
        }
        return -1;
    }
};
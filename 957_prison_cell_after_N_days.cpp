class Solution {
public:
    vector<int> nextstate(vector<int>& cells){
        vector<int> vec(cells.size(),0);
        for(int i=1;i<7;i++){
            if(cells[i-1]==cells[i+1])
                vec[i]=1;
        }
        return vec;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        bool iscycle=false;
        int cycle=0;
        set<string> s;
        for(int i=0;i<N;i++){
            vector<int> temp=nextstate(cells);
            string str="";
            for(int j=0;j<temp.size();j++){
                str=str+to_string(temp[j]);  
            }
            if(s.find(str)!=s.end()){
                iscycle=true;
                break;
            }
            cells=temp;
            cycle++;
            s.insert(str);
        }
        if(iscycle)
            return prisonAfterNDays(cells,N%cycle);
        return cells;
    }
};
class Solution {
public:
    struct comp{
        bool operator()(pair<char,int>& a,pair<char,int>& b){
            return a.second< b.second;
        }
    };
    
    string reorganizeString(string S) {
      map<char,int> mp;
      for(auto c:S){
          mp[c]++;
      }
      priority_queue<pair<char,int>, vector<pair<char,int>>, comp> q;
      for(auto p:mp){
          q.push(make_pair(p.first,p.second));
      }
      string res="";
      while(q.size()>1){
          auto p1=q.top();
          q.pop();
          res+=p1.first;
          auto p2=q.top();
          q.pop();
          res+=p2.first;
          if(p1.second>1){
              q.push(make_pair(p1.first,p1.second-1));
          }
          if(p2.second>1){
              q.push(make_pair(p2.first,p2.second-1));
          }
      }
      if(q.size()>0){
          auto temp=q.top();
          if(temp.second>1)
            return "";
          res+=temp.first;
      }
    return res;
    }
};
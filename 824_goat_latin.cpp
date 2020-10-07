class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> str;
        string temp="";
        for(int i=0;i<S.size();i++){
            
            if(S[i]==' '){
                str.push_back(temp);
                temp.clear();
                continue;
            }
            temp+=S[i];
        }
        str.push_back(temp);
        string res="";
        int count=1;
      
        for(auto word:str){
            if(word[0]=='a'|| word[0]=='e' || word[0]=='i'|| word[0]=='o' || word[0]=='u'||word[0]=='A'|| word[0]=='E' || word[0]=='I'|| word[0]=='O' || word[0]=='U'){
                word+= "ma";
                for(int i=0;i<count;i++){
                    word+= "a";
                }
                res+=word + " ";
            }
            else{
                char c=word[0];
                word.erase(word.begin());
                word+=c;
                word+="ma";
                for(int i=0;i<count;i++){
                    word+='a';
                }
                res+=word + " ";
            }
            count++;
        }
        res.pop_back();
        return res;
        
    }
};
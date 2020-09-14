class Solution {
public:
    
    vector<string> split(string str,char ch){
        string s="";
        vector<string> res;
        for(auto c:str){
            if(c==ch){
                res.push_back(s);
                s.clear();
            }
            else
                s.push_back(c);
        }
        res.push_back(s);
        return res;
    }
    
    bool validIPv4(string IP){
        vector<string> vec=split(IP,'.');
        if(vec.size()!=4)
            return false;
        bool flag=false;
        int count=0;
        for(auto s:IP){
            if(s=='.'){
                flag=true;
                count++;
            }
        }
        if(flag&& count==3){
            for(auto str:vec){
                if(str.size()>3 || str.size()==0 || (str.size()>1 &&str[0]=='0') || str> "255"){
                    return false;
                }
                for(char c:str){
                    if(c<'0' || c>'9')
                        return false;
                }
            }
            return true;
        }
            return false;
    }
    
    bool validIPv6(string IP){
        vector<string> vec=split(IP,':');
        if(vec.size()!=8)
            return false;
        int count=0;
        bool flag=false;
        
        for(auto s:IP){
            if(s==':'){
                flag=true;
                count++;
            }
        }
        if(flag && count==7){
            for(auto str:vec){
                if(str.size()==0 || str.size()>4)
                    return false;
                for(auto c:str){
                    if((c>='0' && c<='9') || (c>='a' &&c<='f') || (c>='A' && c<='F'))
                        continue;
                    return false;
                }
            }
            return true;
        }
        return false;
        
    }
    string validIPAddress(string IP) {
        if(validIPv4(IP))
            return "IPv4";
        else if(validIPv6(IP))
            return "IPv6";
        else
            return "Neither";
    }
};
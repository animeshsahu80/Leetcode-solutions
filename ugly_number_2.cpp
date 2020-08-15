class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int,vector<long long int>,greater<long long int>> q;
        if(n==1)
            return 1;
        vector<long long int> v={2,3,5};
        for(auto num:v){
            q.push(num);
        }
        int count=1;
        long long temp;
        while(count<n){
            temp=q.top();
            q.pop();
            if(temp!=q.top() || q.size()==0){
                count++;
                for(auto num:v){
                    q.push(temp*num);
                }
            }
        }
        return int(temp);
    }
};
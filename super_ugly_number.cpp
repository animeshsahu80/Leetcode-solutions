class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1)
            return 1;
        priority_queue<long long int, vector<long long int>,greater<long long int>> q;
        for(auto num:primes){
            q.push(num);
        }
        int count=1;
        long long int temp;
        while(count<n){
            temp=q.top();
            q.pop();
            if(temp!=q.top()|| q.size()==0){
                count++;
                for(auto i:primes){
                    q.push(temp*i);
                }
            }
        }
        return int(temp);
    }
};
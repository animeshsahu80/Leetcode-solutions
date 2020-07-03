class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        long int l=A.size();
        long temp=K;
        vector<int> k;
        while(temp>0){
            k.push_back(temp%10);
            temp=temp/10;
        }
        reverse(k.begin(),k.end());
        int m=k.size();
        vector<int> ans;
        int carry=0;
        while(m>0&&l>0){
            int num=carry+A[l-1]+k[m-1];
            carry=num/10;
            ans.push_back(num%10);
            m--;
            l--;
        }
        int temp1;
        while(m>0 || l>0){
            if(m>0){
                temp1=carry+k[m-1];
                carry=temp1/10;
                ans.push_back(temp1%10);
                m--;
            }
            else{
                temp1=carry+A[l-1];
                carry=temp1/10;
                ans.push_back(temp1%10);
                l--;
            }
        }
        if(carry>0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
    return ans;
    }
};
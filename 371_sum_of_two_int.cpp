class Solution {
public:
    int getSum(int a, int b) {
      unsigned int sum=a^b;
       unsigned int carry=a&b;
        while(carry){
            carry=carry<<1;
            auto temp=sum^carry;
            carry=carry&sum;
            sum=temp;
        }
        return sum;
    }
};
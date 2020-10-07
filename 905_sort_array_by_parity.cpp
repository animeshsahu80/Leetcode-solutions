class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l=0;
        int r=A.size()-1;
        while(l<=r){
            if(A[l]%2==0 && A[r]%2==1){
                l++;
                r--;
            }
            else if(A[l]%2==1&& A[r]%2==0){
                int temp=A[l];
                A[l]=A[r];
                A[r]=temp;
                l++;
                r--;
            }
            else if(A[l]%2==0 && A[r]%2==0){
                l++;
            }
            else
                r--;
        }
        return A;
    }
};
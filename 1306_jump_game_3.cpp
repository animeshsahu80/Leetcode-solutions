class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        bool ans=helper(arr,start,0);
        return ans;
    }
    bool helper(vector<int>& arr, int start,int count){
        if(start<0 || start>=arr.size())
            return false;
        if(count>arr.size())
            return false;
        if(arr[start]==0)
            return true;
        return helper(arr,start+arr[start],count+1)|| helper(arr,start-arr[start],count+1);
    }
};
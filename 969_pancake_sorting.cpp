class Solution {
public:
    int findidx(vector<int>& arr,int val){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==val)
                return i;
        }
        return -1;
    }
    void flip(vector<int>& arr,int idx){
        int s=0;
        while(s<=idx){
            int temp=arr[s];
            arr[s]=arr[idx];
            arr[idx]=temp;
            s++;
            idx--;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int end=arr.size();
        vector<int> res;
        while(end!=1){
            int idx=findidx(arr,end);
            flip(arr,idx);
            flip(arr,end-1);
            res.push_back(idx+1);
            res.push_back(end);
            end--;
        }
        return res;
    }
};
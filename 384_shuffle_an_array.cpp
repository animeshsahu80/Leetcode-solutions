class Solution {
public:
    vector<int> orig;
    vector<int> ran;
    
    Solution(vector<int>& nums) {
        orig=nums;
        ran=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(ran.size()==0)
            return ran;
        for(int i=ran.size()-1;i>=0;i--){
            int temp=ran[i];
            int idx=rand()%(i+1);
            ran[i]=ran[idx];
            ran[idx]=temp;
            
        }
        return ran;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
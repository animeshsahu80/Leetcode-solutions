class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int right=1;
        int count=0;
        for(int i=0;i<light.size();i++){
            if(light[i]>right){
                right=light[i];
            }
            if(i+1==right)
                count++;
        }
        return count;
        
    }
};
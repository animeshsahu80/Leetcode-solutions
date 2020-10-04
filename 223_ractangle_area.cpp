class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long a=((long)C-(long)A)*((long)D-(long)B);
        long b=((long)G-(long)E)*((long)H-(long)F);
        
        long overlap=max(min((long)C,(long)G)-max((long)A,(long)E),0l)*max(min((long)D,(long)H)-max((long)F,(long)B),0l);
        return (int)(a+b-overlap);
        
    }
};
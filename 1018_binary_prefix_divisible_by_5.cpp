class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int iCurr = 0;
	vector<bool> vRes;
	for (auto n : A) {
		iCurr = (iCurr << 1) | n;
		vRes.push_back(iCurr % 5 == 0);
        iCurr%=10;
	}
	return vRes;
    }
};
struct compare
{
  bool operator()(pair<int,vector<int>> &a,pair<int,vector<int>> &b)
  {
      return a.first>b.first;
  }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,compare> pq;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
            }
        }
        vector<vector<int>> v;
        while(!pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
            if(v.size()==k)
            {
                break;
            }
        }
        return v;
    }
};
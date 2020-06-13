/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res=0, n=employees.size();
        unordered_map <int , Employee*> mp;
        for(int i=0;i<n;i++){
            mp.insert(make_pair(employees[i]->id,employees[i]));
        }
        queue<int>q;
        q.push(id);
        while(q.size()>0){
            int idx=q.front();
            q.pop();
            Employee* temp=mp[idx];
            res+=mp[idx]->importance;
            for(int i=0;i<mp[idx]->subordinates.size();i++){
                q.push(mp[idx]->subordinates[i]);
            }
        }
        return res;
    }
};
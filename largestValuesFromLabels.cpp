#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> ve;
        for(int i = 0; i < values.size(); ++i)
        {
            ve.push_back({values[i],labels[i]});
        }
        sort(ve.begin(), ve.end());
        reverse(ve.begin(), ve.end());
        int i = 0;
        map<int, int> m;
        int ans = 0;
        int t = 0;
        while(t < numWanted && i < ve.size())
        {
             int v = ve[i].first;
             int l = ve[i].second;
             if(m.find(l) == m.end())
             {
                 ++m[l];
                 ans += v;
                 ++t;
                 ++i;
                 continue;
             }
             else if(m[l] < useLimit)
             {
                 ++m[l];
                 ans += v;
                 ++t;
                 ++i;
                 continue;
             }
             else
             ++i;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> values = {5, 4, 3, 2, 1};
    vector<int> labels = {1, 1, 2, 2, 3};
    int numWanted = 3;
    int useLimit = 1;
    // Another test case by Leetcode values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
    // Output: 12
    // [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
    // Output: 16
    cout<< sol.largestValsFromLabels(values, labels, numWanted, useLimit)<< endl;
    return 0;
}

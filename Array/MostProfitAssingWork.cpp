// 826. Most Profit Assigning Work

#define all(v) v.begin(), v.end()

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        sort(all(worker));
        int n = profit.size(), maxP = 0, totalP = 0;
        vector<pair<int,int>> jobs(n);
        
        for(int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        sort(all(jobs));
        
        int j = 0;
        for (int w : worker) {
            while (j < n && jobs[j].first <= w) {
                maxP = max(maxP, jobs[j].second);
                ++j;
            }
            totalP += maxP;
        }
        return totalP;
    }
};

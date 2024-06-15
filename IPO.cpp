class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        // Pair of (capital, profit)
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort projects based on the capital required
        sort(projects.begin(), projects.end());

        // Max heap to store profits of the projects we can afford
        priority_queue<int> maxHeap;
        
        int index = 0;
        for (int i = 0; i < k; ++i) {
            // Add all affordable projects to the max heap
            while (index < projects.size() && projects[index].first <= w) {
                maxHeap.push(projects[index].second);
                ++index;
            }

            // If there are no affordable projects left, break
            if (maxHeap.empty()) break;

            // Select the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};

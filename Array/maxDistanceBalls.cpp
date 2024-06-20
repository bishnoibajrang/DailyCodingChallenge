class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        // Sort the positions
        sort(pos.begin(), pos.end());

        // If only two balls, maximum distance is between the first and last positions
        if (m == 2) {
            return pos.back() - pos[0];
        }

        // Binary search for the maximum minimum distance
        int left = 1;
        int right = pos.back() - pos[0];
        int res = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceBall(pos, m, mid)) {
                res = mid;
                left = mid + 1; // Increase the distance
            } else {
                right = mid - 1; // Decrease the distance
            }
        }
        return res;
    }

private:
    bool canPlaceBall(const vector<int>& pos, int m, int dist) {
        int count = 1; // First ball is placed at pos[0]
        int lastPos = pos[0];
        for (int i = 1; i < pos.size(); ++i) {
            if (pos[i] - lastPos >= dist) {
                ++count;
                lastPos = pos[i];
                if (count == m) {
                    return true;
                }
            }
        }
        return false;
    }
};

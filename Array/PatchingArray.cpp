class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // Disable synchronization between C and C++ standard streams for faster I/O
        ios::sync_with_stdio(false);
        // Untie cin from cout to speed up input and output operations
        cin.tie(nullptr);
        cout.tie(nullptr);

        long x = 1; // Represents the smallest number that we can't form yet
        int patches = 0; // Count of patches added

        // Iterate until x exceeds n
        for (int i = 0; x <= n;) {
            // If the current element in nums is less than or equal to x
            // it means we can extend the range of numbers we can form
            if (i < nums.size() && nums[i] <= x) {
                x += nums[i++]; // Add nums[i] to x and move to the next element
            } else {
                x <<= 1; // Double x (equivalent to adding a patch)
                ++patches; // Increment the patch count
            }
        }

        return patches; // Return the total number of patches added
    }
};

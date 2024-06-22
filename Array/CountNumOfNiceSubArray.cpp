class Solution {
public:
    int f(vector<int>& nums, int k) {
        if(k<0) return 0;
        int n= nums.size();
        int l= 0;
        int r= 0;
        int sum= 0;
        int cnt= 0;
        while(r<n) {
            sum= sum+(nums[r]%2);
            while(sum>k) {
                sum= sum-(nums[l]%2);
                l++;
            }
            cnt= cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        return (f(nums, k) - f(nums, k-1));
    }
};

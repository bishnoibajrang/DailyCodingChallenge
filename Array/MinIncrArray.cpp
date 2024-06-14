class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

        sort(nums.begin(),nums.end());
        int moves = 0;
        int need = nums[0];

        for(int num:nums){
            moves += max(0,need-num);
            need = max(need,num)+1;
        }
        return moves;
    }
};

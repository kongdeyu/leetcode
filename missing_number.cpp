class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(size_t idx = 0; idx < nums.size(); idx++)
        {
            res ^= ((idx + 1) ^ nums[idx]);
        }
        return res;
    }
};
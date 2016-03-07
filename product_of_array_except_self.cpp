class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        assert(nums.size());
        
        std::vector<int> res(nums.size(), 1);
        for(int idx = 1; idx < nums.size(); idx++)
        {
            res[idx] = res[idx - 1] * nums[idx - 1];
        }
        
        int temp = 1;
        for(int idx = nums.size() - 2; idx >= 0; idx--)
        {
            temp *=  nums[idx + 1];
            res[idx] *= temp;
        }
        
        return res;
    }
};
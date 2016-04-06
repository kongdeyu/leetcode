class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int> > res;
        permute_recursive(nums, 0, res);
        return res;
    }
    
private:
    void permute_recursive(std::vector<int> &nums, int begin, std::vector<std::vector<int> > &res)
    {
        if(begin >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(size_t idx = begin; idx < nums.size(); idx++)
        {
            std::swap(nums[begin], nums[idx]);
            permute_recursive(nums, begin + 1, res);
            std::swap(nums[begin], nums[idx]);
        }
    }
};
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int> > res;
        if(k == 0)
        {
            return res;
        }
        
        std::vector<int> nums;
        combination_sum(k, n, nums, res);
        return res;
    }
    
private:
    void combination_sum(int k, int n, std::vector<int> &nums, std::vector<std::vector<int> > &res)
    {
        if(k == 0)
        {
            if(nums.size() && n == 0)
            {
                res.push_back(nums);
            }
            return;
        }
        
        int i = 1;
        if(nums.size())
        {
            i = nums.back() + 1;
        }
        
        for(; i <= 9; i++)
        {
            nums.push_back(i);
            combination_sum(k - 1, n - i, nums, res);
            nums.pop_back();
        }
    }
    
};
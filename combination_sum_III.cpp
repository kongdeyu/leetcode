class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int> > res;
        if(k == 0)
        {
            return res;
        }
        
        std::vector<int> nums;
        return combination_sum(k, n, nums);
    }
    
private:
    std::vector<std::vector<int> > combination_sum(int k, int n, std::vector<int> &nums)
    {
        std::vector<std::vector<int> > res;
        if(k == 0)
        {
            if(nums.size() && n == 0)
            {
                res.push_back(nums);
            }
            return res;
        }
        
        int i = 1;
        if(nums.size())
        {
            i = nums.back() + 1;
        }
        
        for(; i <= 9; i++)
        {
            nums.push_back(i);
            std::vector<std::vector<int> > vec_nums = combination_sum(k - 1, n - i, nums);
            if(vec_nums.size())
            {
                res.insert(res.end(), vec_nums.begin(), vec_nums.end());
            }
            nums.pop_back();
        }
        return res;
    }
    
};
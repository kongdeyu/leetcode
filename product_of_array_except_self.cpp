class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        assert(nums.size());
        
        int n_zero_num = 0;
        int product = 1;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            if(*cit == 0)
            {
                n_zero_num++;
            }
            else
            {
                product *= *cit;
            }
        }
        
        std::vector<int> res(nums.size(), 0);
        if(n_zero_num > 1)
        {
            return res;
        }
        else if(n_zero_num == 1)
        {
            for(size_t idx = 0; idx < nums.size(); idx++)
            {
                if(nums[idx] == 0)
                {
                    res[idx] = product;
                }
            }
        }
        else
        {
            for(size_t idx = 0; idx < nums.size(); idx++)
            {
                res[idx] = product / nums[idx];
            }
        }
        return res;
    }
};
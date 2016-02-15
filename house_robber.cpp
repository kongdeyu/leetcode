class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        int revenue_0 = 0;
        int revenue_1 = nums[0];
        for(std::vector<int>::size_type i = 1; i < nums.size(); i++)
        {
            int cur_revenue = std::max(revenue_0 + nums[i], revenue_1);
            revenue_0 = revenue_1;
            revenue_1 = cur_revenue;
        }
        
        return revenue_1;
    }
};

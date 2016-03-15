class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        assert(nums.size());
        
        for(size_t idx = 0; idx < nums.size(); idx++)
        {
            if(nums[idx] == target)
            {
                return idx;
            }
            
            if(nums[idx] >= target)
            {
                return idx;
            }
        }
        return nums.size();
    }
    
};
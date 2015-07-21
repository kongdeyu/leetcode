class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
        {
            return -1;
        }
        
        for(std::string::size_type idx = 0; idx < nums.size() - 1; idx++)
        {
            if(nums[idx] > nums[idx + 1])
            {
                return idx;
            }
        }
        return nums.size() - 1;
    }
};

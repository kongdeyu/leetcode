class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
        {
            return -1;
        }
        
        std::string::size_type left = 0;
        std::string::size_type right = nums.size() - 1;
        while(left < right)
        {
            std::string::size_type middle = (left + right) >> 1;
            if(nums[middle] < nums[middle + 1])
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return left;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        assert(nums.size());
        
        for(std::vector<int>::reverse_iterator rit = nums.rbegin(); rit != nums.rend() - 1; rit++)
        {
            if(*rit < *(rit + 1))
            {
                return *rit;
            }
        }
        return nums.front();
    }
};
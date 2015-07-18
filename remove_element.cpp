class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        for(std::vector<int>::size_type idx = 0; idx < nums.size(); idx++)
        {
            if(nums[idx] == val)
            {
                continue;
            }
            
            nums[cur++] = nums[idx];
        }
        return cur;
    }
};
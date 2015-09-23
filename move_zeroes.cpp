class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty())
        {
            return;
        }
        
        std::vector<int>::size_type fast = 0;
        std::vector<int>::size_type slow = 0;
        while(fast != nums.size())
        {
            if(nums[fast] != 0)
            {
                std::swap(nums[slow++], nums[fast++]);
            }
            else
            {
                fast++;
            }
        }
    }
    
};
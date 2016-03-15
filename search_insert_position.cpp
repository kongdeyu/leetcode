class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        assert(nums.size());
        
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end)
        {
            int middle = begin + (end - begin) / 2;
            if(nums[middle] == target)
            {
                return middle;
            }
            
            if(nums[middle] < target && middle < nums.size() - 1 && nums[middle + 1] > target)
            {
                return middle + 1;
            }
            
            if(nums[middle] > target)
            {
                end = middle - 1;
            }
            else
            {
                begin = middle + 1;
            }
        }
        return begin;
    }
    
};
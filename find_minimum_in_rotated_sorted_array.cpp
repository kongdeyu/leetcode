class Solution {
public:
    int findMin(vector<int>& nums) {
        assert(nums.size());
        
        int left = 0;
        int right = nums.size() - 1;
        while(left < right && nums[left] > nums[right])
        {
            int middle = (left + right) >> 1;
            if(nums[middle] > nums[left])
            {
                left = middle + 1;
            }
            else if(nums[middle] < nums[right])
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        return nums[left];
    }
};
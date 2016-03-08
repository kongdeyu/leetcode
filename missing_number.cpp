class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        size_t begin = 0;
        size_t end = nums.size();
        while(begin < end)
        {
            size_t middle = (begin + end) / 2;
            if(nums[middle] > middle)
            {
                end = middle;
            }
            else
            {
                begin = middle + 1;
            }
        }
        return end;
    }
};
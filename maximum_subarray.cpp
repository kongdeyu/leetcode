#include <climits>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        int max_sum = INT_MIN;
        int cur_sum = 0;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            cur_sum += *cit;
            if(cur_sum > max_sum)
            {
                max_sum = cur_sum;
            }
            
            if(cur_sum < 0)
            {
                cur_sum = 0;
            }
        }
        return max_sum;
    }
};

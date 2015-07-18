class Solution {
public:
    int majorityElement(vector<int>& nums) {
        assert(nums.size());
        
        int res = nums.front();
        int times = 1;
        for(std::vector<int>::const_iterator cit = nums.begin() + 1; cit != nums.end(); cit++)
        {
            if(*cit != res)
            {
                if(--times == 0)
                {
                    res = *cit;
                    times++;
                }
            }
            else
            {
                times++;
            }
        }
        return res;
    }
};
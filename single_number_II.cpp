class Solution {
public:
    int singleNumber(vector<int>& nums) {
        assert(nums.size());
        
        int res = 0;
        for(int i = 0; i < 8 * sizeof(int); i++)
        {
            int mask = 1 << i;
            int sum = 0;
            for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
            {
                if((*cit) & mask)
                {
                    sum++;
                }
            }
            
            if(sum % 3)
            {
                res |= mask;
            }
        }
        return res;
    }
    
};
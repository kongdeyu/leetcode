class Solution {
public:
    int singleNumber(vector<int>& nums) {
        assert(nums.size());
        
        int ones = 0, twos = 0;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            ones = (ones ^ (*cit)) & ~twos;
            twos = (twos ^ (*cit)) & ~ones;
        }
        return ones;
    }
    
};
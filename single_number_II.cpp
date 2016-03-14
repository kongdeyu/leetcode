class Solution {
public:
    int singleNumber(vector<int>& nums) {
        assert(nums.size());
        
        int one_times = 0;
        int two_times = 0;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            int temp = *cit;
            int mask = two_times & temp;
            two_times ^= mask;
            temp ^= mask;
            
            two_times |= (temp & one_times);
            one_times ^= temp;
        }
        
        return one_times | two_times;
    }
    
};
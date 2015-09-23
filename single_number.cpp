class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            res ^= (*cit);
        }
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            sum += *cit;
        }
        
        int total_sum = nums.size() * (nums.size() + 1) / 2;
        return total_sum - sum;
    }
};
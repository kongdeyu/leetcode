class Solution {
public:
    int maxProduct(vector<int>& nums) {
        assert(nums.size());
        
        int max = nums.front();
        int cur_max = nums.front();
        int cur_min = nums.front();
        for(std::vector<int>::const_iterator cit = nums.begin() + 1; cit != nums.end(); cit++)
        {
            int max_temp = cur_max * (*cit);
            int min_temp = cur_min * (*cit);
            if(max_temp < min_temp)
            {
                std::swap(min_temp, max_temp);
            }
            
            cur_max = std::max(*cit, max_temp);
            cur_min = std::min(*cit, min_temp);
            max = std::max(max, cur_max);
        }
        return max;
    }
};
class Solution {
private:
    int single_number(std::vector<int>& nums)
    {
        int res = 0;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            res ^= *cit;
        }
        return res;
    }
    
public:
    vector<int> singleNumber(vector<int>& nums) {
        int indicator = single_number(nums);
        
        assert(indicator != 0);
        
        int divide = 1;
        while((indicator & divide) == 0)
        {
            divide <<= 1;
        }
        
        std::vector<int> part1;
        std::vector<int> part2;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            if((*cit & divide) == 0)
            {
                part1.push_back(*cit);
            }
            else
            {
                part2.push_back(*cit);
            }
        }
        
        std::vector<int> res;
        res.push_back(single_number(part1));
        res.push_back(single_number(part2));
        return res;
    }
};
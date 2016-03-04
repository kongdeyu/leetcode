class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int indicator = 0;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            indicator ^= *cit;
        }
        assert(indicator != 0);
        
        int divide = 1;
        while((indicator & divide) == 0)
        {
            divide <<= 1;
        }
        
        int num1 = 0;
        int num2 = 0;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            if((*cit & divide) == 0)
            {
                num1 ^= *cit;
            }
            else
            {
                num2 ^= *cit;
            }
        }
        
        std::vector<int> res;
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }
};
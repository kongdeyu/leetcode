class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> set_nums;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            if(set_nums.find(*cit) != set_nums.end())
            {
                return true;
            }
            set_nums.insert(*cit);
        }
        return false;
    }
};
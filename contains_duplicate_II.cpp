class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int, int> num2idx;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            std::map<int, int>::const_iterator cit2map = num2idx.find(*cit);
            if(cit2map != num2idx.end())
            {
                if(cit - nums.begin() - cit2map->second <= k)
                {
                    return true;
                }
            }
            num2idx[*cit] = cit - nums.begin();
        }
        return false;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res;
        if(nums1.empty() || nums2.empty())
        {
            return res;
        }
        
        std::set<int> set_nums1;
        for(std::vector<int>::const_iterator cit = nums1.begin(); cit != nums1.end(); cit++)
        {
            set_nums1.insert(*cit);
        }
        
        std::set<int> set_nums2;
        for(std::vector<int>::const_iterator cit = nums2.begin(); cit != nums2.end(); cit++)
        {
            set_nums2.insert(*cit);
        }
        
        for(std::set<int>::const_iterator cit = set_nums1.begin(); cit != set_nums1.end(); cit++)
        {
            if(set_nums2.find(*cit) != set_nums2.end())
            {
                res.push_back(*cit);
            }
        }
        return res;
    }
    
};
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res;
        if(nums1.empty() || nums2.empty())
        {
            return res;
        }
        
        std::map<int, std::vector<int> > map_nums1;
        for(std::vector<int>::const_iterator cit = nums1.begin(); cit != nums1.end(); cit++)
        {
            map_nums1[*cit].push_back(*cit);
        }
        
        std::map<int, std::vector<int> > map_nums2;
        for(std::vector<int>::const_iterator cit = nums2.begin(); cit != nums2.end(); cit++)
        {
            map_nums2[*cit].push_back(*cit);
        }
        
        for(std::map<int, std::vector<int> >::const_iterator cit = map_nums1.begin(); cit != map_nums1.end(); cit++)
        {
            if(map_nums2.find(cit->first) != map_nums2.end())
            {
                res.insert(res.end(), std::min(cit->second.size(), map_nums2[cit->first].size()), cit->first);
            }
        }
        return res;
    }
    
};
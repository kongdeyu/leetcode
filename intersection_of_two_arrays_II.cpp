class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res;
        if(nums1.empty() || nums2.empty())
        {
            return res;
        }
        
        std::map<int, int> map_nums1;
        for(std::vector<int>::const_iterator cit = nums1.begin(); cit != nums1.end(); cit++)
        {
            if(map_nums1.find(*cit) != map_nums1.end())
            {
                map_nums1[*cit]++;
            }
            else
            {
                map_nums1[*cit] = 1;
            }
        }
        
        std::map<int, int> map_nums2;
        for(std::vector<int>::const_iterator cit = nums2.begin(); cit != nums2.end(); cit++)
        {
            if(map_nums2.find(*cit) != map_nums2.end())
            {
                map_nums2[*cit]++;
            }
            else
            {
                map_nums2[*cit] = 1;
            }
        }
        
        for(std::map<int, int>::const_iterator cit = map_nums1.begin(); cit != map_nums1.end(); cit++)
        {
            if(map_nums2.find(cit->first) != map_nums2.end())
            {
                res.insert(res.end(), std::min(cit->second, map_nums2[cit->first]), cit->first);
            }
        }
        return res;
    }
    
};
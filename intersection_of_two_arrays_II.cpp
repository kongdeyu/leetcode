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
        
        for(std::vector<int>::const_iterator cit = nums2.begin(); cit != nums2.end(); cit++)
        {
            if(map_nums1.find(*cit) != map_nums1.end() && map_nums1[*cit] > 0)
            {
                map_nums1[*cit]--;
                res.push_back(*cit);
            }
        }
        return res;
    }
    
};
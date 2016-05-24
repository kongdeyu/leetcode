class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res;
        if(nums1.empty() || nums2.empty())
        {
            return res;
        }
        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int>::size_type idx1 = 0;
        std::vector<int>::size_type idx2 = 0;
        while(idx1 < nums1.size() && idx2 < nums2.size())
        {
            if(nums1[idx1] < nums2[idx2])
            {
                idx1++;
            }
            else if(nums1[idx1] > nums2[idx2])
            {
                idx2++;
            }
            else
            {
                res.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            }
        }
        return res;
    }
    
};
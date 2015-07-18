class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> res;
        if(nums.empty())
        {
            return res;
        }
        
        int start = nums.front();
        int stop = nums.front();
        int span = 1;
        for(std::vector<int>::const_iterator cit = nums.begin() + 1; cit != nums.end(); cit++)
        {
            if(*cit == start + span)
            {
                stop = *cit;
                span++;
            }
            else
            {
                res.push_back(nums2range(start, stop));
                start = *cit;
                stop = *cit;
                span = 1;
            }
        }
        res.push_back(nums2range(start, stop));
        return res;
    }
    
    std::string nums2range(int start, int stop)
    {
        std::stringstream ss;
        if(start == stop)
        {
            ss << start;
        }
        else
        {
            ss << start << "->" << stop;
        }
        return ss.str();
    }
};
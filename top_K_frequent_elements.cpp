class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> res;
        if(nums.empty())
        {
            return res;
        }
        
        std::map<int, int> map_num2times;
        for(std::vector<int>::const_iterator cit = nums.begin(); cit != nums.end(); cit++)
        {
            std::map<int, int>::iterator it2num = map_num2times.find(*cit);
            if(it2num == map_num2times.end())
            {
                map_num2times[*cit] = 1;
            }
            else
            {
                map_num2times[*cit]++;
            }
        }
        
        std::vector<std::vector<int> > times2num(nums.size(), std::vector<int>());
        for(std::map<int, int>::iterator it2num = map_num2times.begin(); it2num != map_num2times.end(); it2num++)
        {
            times2num[it2num->second - 1].push_back(it2num->first);
        }
        
        int size_of_res = 0;
        for(int idx = times2num.size() - 1; idx >= 0; idx--)
        {
            if(times2num[idx].empty())
            {
                continue;
            }
            
            for(std::vector<int>::const_iterator cit2num = times2num[idx].begin(); cit2num != times2num[idx].end(); cit2num++)
            {
                res.push_back(*cit2num);
                if(++size_of_res == k)
                {
                    return res;
                }
            }
        }
        return res;
    }
    
};
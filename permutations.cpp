class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int> > res;
        if(nums.empty())
        {
            return res;
        }
        
        for(std::vector<int>::const_iterator cit2num = nums.begin(); cit2num != nums.end(); cit2num++)
        {
            int cur_num = *cit2num;
            if(res.empty())
            {
                res.push_back(std::vector<int>(1, cur_num));
                continue;
            }
            
            std::vector<std::vector<int> > temp;
            temp.swap(res);
            for(std::vector<std::vector<int> >::const_iterator cit2temp = temp.begin(); cit2temp != temp.end(); cit2temp++)
            {
                std::vector<int> cur_row = *cit2temp;
                for(size_t idx = 0; idx <= cur_row.size(); idx++)
                {
                    std::vector<int> new_row(cur_row);
                    new_row.insert(new_row.begin() + idx, cur_num);
                    res.push_back(new_row);
                }
            }
        }
        
        return res;
    }
};
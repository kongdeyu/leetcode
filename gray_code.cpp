class Solution {
public:
    vector<int> grayCode(int n) {
        assert(n >= 0);
        
        std::vector<int> res;
        res.push_back(0);
        for(int i = 0; i < n; i++)
        {
            int highbit = 1 << i;
            for(int j = res.size() - 1; j >= 0; j--)
            {
                res.push_back(res[j] + highbit);
            }
        }
        return res;
    }
    
};
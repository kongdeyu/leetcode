class Solution {
public:
    vector<int> grayCode(int n) {
        assert(n >= 0);
        
        int num = 0;
        for(int i = 0; i < n; i++)
        {
            num = ((num << 1) ^ 1);
        }
        
        std::vector<int> res;
        for(int i = 0; i <= num; i++)
        {
            int temp = (i / 2) ^ i;
            res.push_back(temp);
        }
        return res;
    }
    
};
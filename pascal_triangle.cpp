class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int> > res;
        if(numRows < 1)
        {
            return res;
        }
        
        res.push_back(std::vector<int>(1, 1));
        for(int i = 1; i < numRows; i++)
        {
            std::vector<int> temp(1, 1);
            for(int j = 0; j < i - 1; j++)
            {
                temp.push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};
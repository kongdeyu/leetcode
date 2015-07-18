class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> res;
        if(rowIndex < 0)
        {
            return res;
        }
        
        res.push_back(1);
        for(int i = 1; i <= rowIndex; i++)
        {
            std::vector<int> temp;
            temp.push_back(1);
            for(int j = 0; j < i - 1; j++)
            {
                temp.push_back(res[j] + res[j + 1]);
            }
            temp.push_back(1);
            res.swap(temp);
        }
        return res;
    }
};
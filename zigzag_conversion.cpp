class Solution {
public:
    string convert(string s, int numRows) {
        std::string res;
        if(numRows < 1)
        {
            return res;
        }
        
        if(numRows == 1)
        {
            return s;
        }
        
        for(int i = 0; i < numRows; i++)
        {
            int j = i;
            while(true)
            {
                if(j >= s.size())
                {
                    break;
                }
                res.push_back(s[j]);
                j += (2 * numRows - 2);
                if(i > 0 && i < numRows - 1 && j - i * 2< s.size())
                {
                    res.push_back(s[j - i * 2]);
                }
            }
        }
        return res;
    }
};
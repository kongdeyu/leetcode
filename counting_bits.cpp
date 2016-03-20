class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> res;
        for(int i = 0; i <= num; i++)
        {
            int temp = i;
            int num = 0;
            while(temp > 0)
            {
                if(temp & 1)
                {
                    num++;
                }
                temp >>= 1;
            }
            res.push_back(num);
        }
        return res;
    }
};
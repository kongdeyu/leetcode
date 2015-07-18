class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
        {
            return 0;
        }
        int res = n - 2;
        std::vector<bool> flag(n - 1, true);
        flag[0] = false;
        for(int i = 2; i < n; i++)
        {
            if(!flag[i])
            {
                continue;
            }
            for(int j = 2; j * i < n; j++)
            {
                if(flag[j * i])
                {
                    flag[j * i] = false;
                    res--;
                }
            }
        }
        return res;
    }
};
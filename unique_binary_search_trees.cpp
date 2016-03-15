class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
        {
            return 0;
        }
        
        std::vector<int> vec_num(n + 1, 0);
        vec_num[0] = 1;
        vec_num[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                vec_num[i] += vec_num[j - 1] * vec_num[i - j];
            }
        }
        
        return vec_num[n];
    }
    
};
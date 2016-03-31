class Solution {
public:
    int uniquePaths(int m, int n) {
        assert(m > 0 && m <=100 && n > 0 && n <=100);
        if(m == 1 || n == 1)
        {
            return 1;
        }
        
        std::vector<int> vec_path(n, 1);
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                vec_path[j] += vec_path[j - 1];
            }
        }
        return vec_path[n - 1];
    }
    
};
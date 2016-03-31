class Solution {
public:
    int uniquePaths(int m, int n) {
        assert(m > 0 && m <=100 && n > 0 && n <=100);
        
        std::vector<int> vec_path(m * n, -1);
        return unique_paths(m, n, m, n, vec_path);
    }
    
private:
    int unique_paths(int i, int j, int m, int n, std::vector<int> &vec_path)
    {
        if(i == 1 || j == 1)
        {
            return 1;
        }
        
        if(vec_path[(i - 1) * n + j - 1] == -1)
        {
            vec_path[(i - 1) * n + j - 1] = unique_paths(i - 1, j, m, n, vec_path) + unique_paths(i, j - 1, m, n, vec_path);
        }
        
        return vec_path[(i - 1) * n + j - 1];
    }
    
};
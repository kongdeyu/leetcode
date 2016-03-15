class Solution {
private:
    std::vector<int> _vec_times;
    
    int num_trees(int n)
    {
        if(n == 0)
        {
            return 1;
        }
        
        if(_vec_times.size() >= n && _vec_times[n - 1] != -1)
        {
            return _vec_times[n - 1];
        }
        
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            int left = num_trees(i - 1);
            int right = num_trees(n - i);
            res += left * right;
        }
        
        if(_vec_times.size() < n)
        {
            _vec_times.resize(n, -1);
        }
        _vec_times[n - 1] = res;
        
        return res;
    }
    
public:
    int numTrees(int n) {
        if(n == 0)
        {
            return 0;
        }
        
        return num_trees(n);
    }
    
};
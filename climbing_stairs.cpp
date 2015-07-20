class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
        {
            return 0;
        }
        
        if(n == 1)
        {
            return 1;
        }
        
        if(n == 2)
        {
            return 2;
        }
        
        if(n >= _cache.size() || _cache[n] == 0)
        {
            int32_t ways = climbStairs(n - 1) + climbStairs(n - 2);
            if(n >= _cache.size())
            {
                _cache.resize(n + 1, 0);
            }
            _cache[n] = ways;
            return ways;
        }
        return _cache[n];
    }
    
private:
    std::vector<int> _cache;
};
class Solution {
public:
    int integerBreak(int n) {
        if(n < 2)
        {
            return 0;
        }
        
        if(_m_vec_max_product.size() < n)
        {
            _m_vec_max_product.resize(n, 0);
            _m_vec_max_product[1] = 1;
        }
        
        if(_m_vec_max_product[n - 1] != 0)
        {
            return _m_vec_max_product[n - 1];
        }
        
        int max_product = 0;
        for(int i = 1; i <= n / 2; i++)
        {
            int left = std::max(i, integerBreak(i));
            int right = std::max(n - i, integerBreak(n - i));
            int cur_product = left * right;
            if(cur_product > max_product)
            {
                max_product = cur_product;
            }
        }
        _m_vec_max_product[n - 1] = max_product;
        return max_product;
    }
    
private:
    std::vector<int> _m_vec_max_product;
    
};
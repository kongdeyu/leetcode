class Solution {
public:
    int integerBreak(int n) {
        assert(n > 1);
        
        if(n == 2)
        {
            return 1;
        }
        
        if(n == 3)
        {
            return 2;
        }
        
        int q1 = 1;
        int q2 = 2;
        int q3 = 3;
        int q4 = 0;
        for(int i = 4; i <= n; i++)
        {
            q4 = std::max(q2 * 2, q1 * 3);
            q1 = q2;
            q2 = q3;
            q3 = q4;
        }
        return q4;
    }
    
};
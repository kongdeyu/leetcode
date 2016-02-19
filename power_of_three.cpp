#include <climits>
#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
        {
            return false;
        }
        
        int max_exp = int(log(INT_MAX) / log(3));
        int max_power = pow(3, max_exp);
        return !(max_power % n);
    }
};
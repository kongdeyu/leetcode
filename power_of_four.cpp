class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num > 0)
        {
            if(num == 1)
            {
                return true;
            }
            
            if((num & 3) != 0)
            {
                return false;
            }
            
            num >>= 2;
        }
        return false;
    }
    
};
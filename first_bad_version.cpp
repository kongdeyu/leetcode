// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        assert(n > 0);
        
        if(isBadVersion(1))
        {
            return 1;
        }
        
        if(!isBadVersion(n))
        {
            return 0;
        }
        
        int left = 2;
        int right = n;
        while(left < right)
        {
            int middle = left + ((right - left) >> 1);
            if(isBadVersion(middle))
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        return right;
    }
    
};
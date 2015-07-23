class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty())
        {
            return 0;
        }
        
        int start = 0;
        int stop = height.size() - 1;
        int max_area = (stop - start) * std::min(height[start], height[stop]);
        while(true)
        {
            int height_left = height[start];
            int height_right = height[stop];
            if(height_left < height_right)
            {
                while(start < stop && height[start] <= height_left)
                {
                    start++;
                }
            }
            else
            {
                while(start < stop && height[stop] <= height_right)
                {
                    stop--;
                }
            }
            
            if(start >= stop)
            {
                break;
            }
            
            max_area = std::max(max_area, (stop - start) * std::min(height[start], height[stop]));
        }
        
        return max_area;
    }
};
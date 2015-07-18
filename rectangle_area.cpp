class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = 0;
        if(A < C && B < D)
        {
            area1 = (C - A) * (D - B);
        }
        int area2 = 0;
        if(E < G && F < H)
        {
            area2 = (G - E) * (H - F);
        }
        if(area1 == 0 || area2 == 0)
        {
            return area1 + area2;
        }
        
        int x1 = std::max(A, E);
        int y1 = std::max(B, F);
        int x2 = std::min(C, G);
        int y2 = std::min(D, H);
        int area_common = 0;
        if(x1 < x2 && y1 < y2)
        {
            area_common = (x2 - x1) * (y2 - y1);
        }
        return area1 + area2 - area_common;
    }
};
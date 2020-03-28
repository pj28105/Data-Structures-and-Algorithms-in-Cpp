// Note -> Bottom left and top right co-ordinates are given

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       int x = min(rec1[2],rec2[2]);
       int y = min(rec1[3],rec2[3]);
       int x1 = max(rec1[0],rec2[0]);
       int y1 = max(rec1[1],rec2[1]);
       if(x1 < x && y1 < y)
           return 1;
        return 0;
    }
};

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = 0,area2 = 0,area3 = 0;
        area1 = (C - A) * (D - B);
        area2 += (G - E) * (H - F);
        // Overlap
        int x = min(C,G);
        int y = min(D,H);
        int x1 = max(A,E);
        int y1 = max(B,F);
        if(x > x1 && y > y1){
            area3 = (x - x1) * (y - y1);
        }
        int ans = (area1 - area3) + area2;
        return ans;
    }
};
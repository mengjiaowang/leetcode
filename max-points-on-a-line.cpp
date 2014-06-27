class Solution {
    public:
        int maxPoints(vector<Point> &points) {
            int maxCount = 0;
            if(points.size() == 0) return maxCount;
            for(int i = 0; i != points.size(); ++i){
                int count = 0, n = 0;
                unordered_map<double, int> umap;
                for(int j = 0; j != points.size(); ++j){
                    int dx = points[j].x - points[i].x;
                    int dy = points[j].y - points[i].y;
                    double slope = std::numeric_limits<double>::infinity();
                    if(dx == 0 && dy == 0){n ++; continue;}
                    else if(dx != 0) slope = ((double)dy)/dx;
                    int tmp = 0;
                    if(umap.find(slope) != umap.end()) tmp = umap[slope];
                    umap[slope] = tmp + 1;
                    if(count < tmp + 1) count = tmp + 1;
                }
                if(maxCount < count + n) maxCount = count + n;
            }
            return maxCount;
        }
};

class Solution {
    public:
        int maxPoints(vector<Point> &points) {
            int maxCount = 0;
            for(int i = 0; i != points.size(); ++i){
                for(int j = 0; j < i; ++j){
                    int count = 0;
                    for(int k = 0; k != points.size(); ++k){
                        if(k != i && k !=j){
                            if(points[i].x == points[j].x){
                                if(points[k].x == points[i].x) count ++;
                            }
                            else if(points[i].y == points[j].y){
                                if(points[k].y == points[i].y) count ++;
                            }
                            else{
                                if((points[k].y-points[i].y)/(points[j].y-points[i].y)-(points[k].x-points[i].x)/(points[j].x-points[i].x) == 0) count ++;
                            }
                        }
                    }
                    if(count > maxCount) maxCount = count;
                }
            }
            return maxCount;
        }
};

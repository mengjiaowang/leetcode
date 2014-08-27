/**
 ** Definition for an interval.
 ** struct Interval {
 **     int start;
 **     int end;
 **     Interval() : start(0), end(0) {}
 **     Interval(int s, int e) : start(s), end(e) {}
 ** };
 **/

bool cmp(const Interval &lhs, const Interval &rhs){
    return lhs.start < rhs.start;
}

class Solution {
    public:
        vector<Interval> merge(vector<Interval> &intervals) {
            vector<Interval> result;
            if(intervals.size() == 0) return result;
            sort(intervals.begin(), intervals.end(), cmp);
            stack<Interval> s;
            s.push(intervals[0]);
            for(int i = 1; i < intervals.size(); ++i){
                if(s.top().end >= intervals[i].start){
                    s.top().end = intervals[i].end > s.top().end ? intervals[i].end:s.top().end;
                }
                else
                {
                    s.push(intervals[i]);
                }
            }
            while(!s.empty()){
                result.push_back(s.top());
                s.pop();
            }
            return result;
        }
};

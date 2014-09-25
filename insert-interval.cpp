class Solution {
    public:
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            vector<Interval> result;
            if(intervals.size() == 0){
                result.push_back(newInterval);
                return result;
            }
            int i = 0, start = 0, end = 0;
            for(; i != intervals.size(); ++i){
                if(intervals[i].end < newInterval.start){
                    result.push_back(intervals[i]);
                }else{
                    break;
                }
            }
            if(i == intervals.size()){
                result.push_back(newInterval);
                return result;
            }
            start = min(intervals[i].start, newInterval.start);
            for(; i != intervals.size(); ++i){
                if(intervals[i].end >= newInterval.end){
                    if(intervals[i].start > newInterval.end)
                    {
                        end = newInterval.end;
                        break;
                    }
                    else{
                        end = intervals[i].end;
                        ++i;
                        break;
                    }
                }
                else if(intervals[i].end < newInterval.end){
                    if(i == intervals.size()-1){
                        end = newInterval.end;
                    }
                    else if(newInterval.end < intervals[i+1].start){
                        end = newInterval.end;
                        ++i;
                        break;
                    }
                    else if(newInterval.end >= intervals[i+1].start && newInterval.end < intervals[i+1].end){
                        end = intervals[i+1].end;
                        i += 2;
                        break;
                    }
                }
            }
            Interval mid(start, end);
            result.push_back(mid);
            for(; i != intervals.size(); ++i){
                result.push_back(intervals[i]);
            }
            return result;
        }
};

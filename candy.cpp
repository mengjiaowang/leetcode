/*
 *
 1.Check increasing peak move until max-peak -> add the additional candies;
 2.Check the decreasing of peak -> move to depression, add the additional 
   candies for only the decreasing sequence after the peak;
 3.Then check the range of decreasing & previous increasing sequence, adjust
   the max-peak candies [by adding additional candies to sum] only if the 
   range of decreasing is > range of increasing and that would = (decreasing
   range - increasing range) [ otherwise, everything's in place;
 4.If it's flat [i.e adjacent ratings are same], just move on, everything's in place. 

*/

class Solution {
    public:
        int candy(vector<int> &ratings) {
            int num = ratings.size(), i = 0;
            while(i < ratings.size() - 1){
                int start = i;
                while(ratings[i] < ratings[i+1] && i < ratings.size() - 1) ++i;
                int range1 = i - start; 
                num += ((range1+1)*range1)/2;
                if(i == ratings.size() - 1) break;

                start = i;
                while(ratings[i] > ratings[i+1] && i < ratings.size() - 1) ++i;
                int range2 = i - start - 1;
                num += ((range2+1)*range2)/2;
                if(range2 + 1 > range1) num += range2 + 1 - range1;
                if(i == ratings.size() - 1) break;
                if(ratings[i] == ratings[i+1] && i < ratings.size() - 1) ++i;
            }
            return num;
        }
};

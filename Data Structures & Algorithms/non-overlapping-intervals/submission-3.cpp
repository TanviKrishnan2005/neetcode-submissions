class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](auto&a,auto&b){
            return a[1]<b[1];
        });

        int res =0;//ow many intervals we remove
        int prevEnd=intervals[0][1];//end of the first interval
        for(int i =1;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start<prevEnd){//The interval overlaps with the previous one
                res++;
            }else{//no overlap
                prevEnd = end;
            }
        }
        return res;
    }
};

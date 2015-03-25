#include <vector>
#include <stdio.h>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool cmp_interval(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp_interval);
        Interval prev = intervals[0];
        vector<Interval> merge_intervals;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > prev.end) {
                merge_intervals.push_back(prev);
                prev = intervals[i];
            } else {
                int temp_start = prev.start < intervals[i].start ? prev.start : intervals[i].start;
                int temp_end = prev.end < intervals[i].end ? intervals[i].end : prev.end;
                Interval temp(temp_start, temp_end);
                prev = temp;
            }
        }
        merge_intervals.push_back(prev);       
        return merge_intervals;
    }
};

int main() {
    int test[4][2] = {
        {1,3},
        {2,6},
        {8,10},
        {15,18} 
    };
    vector<Interval> intervals;
    for (int i = 0; i < 4; i++) {
        Interval itv(test[i][0], test[i][1]);
        intervals.push_back(itv);
    }
    Solution s;
    vector<Interval> res = s.merge(intervals);
    for (int i = 0; i < res.size(); i++) {
        printf("[%d, %d] ", res[i].start, res[i].end);
    }
    printf("\n");
    
    int test1[2][2] = {
        {1,4},
        {0,0}
    };
    intervals.clear();
    for (int i = 0; i < 2; i++) {
        Interval itv(test1[i][0], test1[i][1]);
        intervals.push_back(itv);
    }
    res = s.merge(intervals);
    for (int i = 0; i < res.size(); i++) {
        printf("[%d, %d] ", res[i].start, res[i].end);
    }
    printf("\n");
}

/**
 * =====================================================================================                                                                                                                                                    
 *
 *       Filename:  InsertInterval.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Problem: Insert Interval 
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Hide Tags Array Sort

解题思路：
顺次扫描，判断当前位置i和newInterval的start, end关系，决定插入，合并插入，还是跳过。主要是细心，
1. 循环结束后要记得newInterval可能插在最末尾或者在末尾合并的情况
2. 当遇见相等的情况，表示是可以合并的，比如：[[1,5]], [5,7]，输出结果应该是[[1,7]]
几个testcase的验证结果：
[[1,5], [6,9]], [2,5] ==> [[1,5], [6,9]]
[[1,5]], [2,3] ==> [[1,5]]
[[1,5]], [5,7] ==> [[1,7]]
[[1,2], [3,5], [6,7], [8,10], [12,16]], [4,9] ==> [1,2],[3,10],[12,16] 
*/

#include <vector>
#include <stdio.h>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 
public:
    void printIntervals(vector<Interval> &intervals) {
        for (int i = 0; i < intervals.size(); i++) {
            printf("[%d, %d] ", intervals[i].start, intervals[i].end);
        }
        printf("\n");
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        bool is_done = false;
        int start_idx = -1;
        int i = 0;
        for (; i < intervals.size(); i++) {
            if (is_done) {
                result.push_back(intervals[i]);
            } else {
                if (newInterval.end < intervals[i].start) {
                    if (i == 0) {
                        result.push_back(newInterval);
                        result.push_back(intervals[i]);
                        is_done = true;
                    } else {
                        if (newInterval.start > intervals[i-1].end) {
                            result.push_back(newInterval);
                            result.push_back(intervals[i]);
                            is_done = true;
                        } else {
                            int new_start = newInterval.start < intervals[start_idx].start ? newInterval.start : intervals[start_idx].start;
                            int new_end = newInterval.end < intervals[i-1].end ? intervals[i-1].end : newInterval.end;
                            Interval temp(new_start, new_end);
                            result.push_back(temp);
                            result.push_back(intervals[i]);
                            is_done = true;
                        }
                    }
                } else {
                    if (newInterval.start < intervals[i].start) {
                        continue;
                    } else {
                        if (newInterval.start <= intervals[i].end) {
                            if (start_idx < 0) {
                                 start_idx = i;
                            }
                        } else {
                            result.push_back(intervals[i]);
                        }
                    }
                }
            }
        }
        if (!is_done) {
            if (i < 1 || newInterval.start > intervals[i-1].end) {
                result.push_back(newInterval);
            } else {
                int new_start = newInterval.start < intervals[start_idx].start ? newInterval.start : intervals[start_idx].start;
                int new_end = newInterval.end < intervals[i-1].end ? intervals[i-1].end : newInterval.end;
                Interval temp(new_start, new_end);
                result.push_back(temp);
            }
        }     
        return result;    
    }
};

int main() {
    int test1[3][2] = {
        {1, 3},
        {6, 9},
        {2, 5}   
    };
    vector<Interval> test_intervals;
    Interval newInterval;
    for (int i = 0; i < 3; i++) {
        Interval itv(test1[i][0], test1[i][1]);
        if (i < 2) {
            test_intervals.push_back(itv);
        } else {
            newInterval = itv;
        }
    }
    Solution s;
    vector<Interval> res = s.insert(test_intervals, newInterval);
    s.printIntervals(res);
    
    int test2[6][2] = {
        {1, 2},
        {3, 5},
        {6, 7},   
        {8, 10},
        {12, 16},   
        {4, 9},   
    };
    test_intervals.clear();
    for (int i = 0; i < 6; i++) {
        Interval itv(test2[i][0], test2[i][1]);
        if (i < 5) {
            test_intervals.push_back(itv);
        } else {
            newInterval = itv;
        }
    }
    res = s.insert(test_intervals, newInterval);
    s.printIntervals(res);
    
    int test3[2][2] = {
        {1, 5},
        {2, 3},
    };
    test_intervals.clear();
    for (int i = 0; i < 2; i++) {
        Interval itv(test3[i][0], test3[i][1]);
        if (i < 1) {
            test_intervals.push_back(itv);
        } else {
            newInterval = itv;
        }
    }
    res = s.insert(test_intervals, newInterval);
    s.printIntervals(res);
}

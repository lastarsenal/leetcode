/**
 * =====================================================================================
 *       Filename:  GasStation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================
 *
[Problem] Gas Station

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Hide Tags Greedy

[解题思路]
1. 从位置0开始，向后遍历，如果跑到gas[i]的时候，向后一站的气不够了，则：
   1.1 从位置0开始不可能顺利的跑完一圈；
   1.2 从位置i+1开始再测试。因为这时能跑完一圈的起始位置肯定不可能是0-i之间的气站，
       假设能从k跑完一圈，k>0&&k<i,因为到gas[i]的时候，余气才<0，所以从0-k跑，跑到gas[k]的时候，余气必然是>=0的
       如果能从k跑完一圈，因为0-k之间对气都是正的贡献，那肯定能从0开始跑完一圈。这与1.1的测试矛盾。
       因此，起始位置只可能是i+1
2. 假设1的测试最后起始位置是j+1，跑到gas[n-1]的时候，余气>0，气站是循环的，需要回到0，但此时不用再逐一检测气能不能跑完一圈到j,
   因为从0->i, i+1->k, k+1->j的余气在1中都已经算了，它们都是负的，只用存起来，然后累加到当前的余气上，如果最后余气还能>=0，则能跑完一圈。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0;
        int retain = 0;
        int i = start;
        vector<int> hist;
        while (i < gas.size()) {
            retain = 0;
            i = start;     
            for (; i < gas.size(); i++) {
                retain += gas[i] - cost[i];
                if (retain < 0) {
                    hist.push_back(retain);
                    start = i + 1;
                    break;
                }
            }
        }
        if (start >= gas.size()) {
            return -1;
        }
        if (retain >= 0 && start > 0) {
            for (int j = 0; j < hist.size(); j++) {
                retain += hist[j];
                if (retain < 0) {
                    return -1;
                }  
            }
        }
        return start;
    }
};

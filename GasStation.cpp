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

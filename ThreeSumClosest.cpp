/**
 *
 * =====================================================================================                                                                                                                                                    
 *
 *       Filename:  ThreeSumClosest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================
Problem:
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Hide Tags Array Two Pointers

解题思路：
跟3Sum类似，3Sum是要找到target，这里不找target，而是可能的最接近target的sum，难度并没有增加，只需稍作条件判断上的改动即可
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int min_gap = INT_MAX;
        int min_sum = 0;
        for (int i = 0; i < num.size(); i++) {
            int j = i+1;
            int k = num.size() - 1;
            while (j < k) {
                if (j > i+1 && num[j] == num[j-1]) {
                    j++;
                    continue;
                }
                if (k < num.size() - 1 && num[k] == num[k+1]) {
                    k--;
                    continue;
                }
                int sum = num[i] + num[j] + num[k];
                int gap = abs(target - sum);
                if (gap == 0) {
                    return sum;
                }
                if (gap < min_gap) {
                    min_gap = gap;
                    min_sum = sum;
                }
                if (target < sum) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return min_sum;
    }
};

int main() {
    Solution s;
    int test_case[3] = {0, 1, 2};
    int target = 3;
    vector<int> num;
    for (int i = 0; i < 3; i++) {
        num.push_back(test_case[i]);
    }
    int gap = s.threeSumClosest(num, target);
    printf("cloasest gap=%d\n", gap);
}


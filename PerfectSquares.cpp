/**************************************
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

基本思路：动态规划

***************************************/
#include <stdio.h>
#include <math.h>
#include <map>

class Solution {
    public:
        int numSquares(int n) {
            int d[n+1];
            d[1] = 1;
            for (int i = 2; i <= n; i++) {
                int min = -1;
                int j = 1;
                while (j * j <= i) {
                    if (j * j == i) {
                        min = 1;
                        break;
                    }
                    int sn = d[i - j * j] + 1;
                    min = (min < 0 || sn < min) ? sn : min;
                    j++;
                }
                d[i] = min;
            }
            return d[n];
        }
};

int main() {
    Solution s;
    int i = 9732;
    int sn = s.numSquares(i);
    printf("nump[%d] perfect squres[%d]\n", i, sn);
}

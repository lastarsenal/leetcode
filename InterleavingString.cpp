/**
 * =====================================================================================                                                                                                                                                    
 *
 *       Filename:  InterleavingString.cpp
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

Problem: Interleaving String 
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Hide Tags Dynamic Programming String
解题思路：动态规划
递归的解法会超时
 */
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        bool flag[1000][1000];
        flag[0][0] = true;
        for (int i = 1; i <= s1.length(); i++) {
            flag[i][0] = flag[i-1][0] && (s3[i-1] == s1[i-1]);
        }
        for (int j = 1; j <= s2.length(); j++) {
            flag[0][j] = flag[0][j-1] && (s3[j-1] == s2[j-1]);
        }
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                flag[i][j] = (flag[i][j-1] && s3[i+j-1] == s2[j-1]) || (flag[i-1][j] && s3[i+j-1] == s1[i-1]);
            }
        }
        return flag[s1.length()][s2.length()];    
    }


    bool isInterleaveV2(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        if (s1.length() == 0 && s2.length() == 0 && s3.length() == 0) {
            return true;
        }
        if (s1.length() == 0) {
            return (s3[0] == s2[0]) && isInterleave(s1, s2.substr(1), s3.substr(1));
        }
        if (s2.length() == 0) {
            return (s3[0] == s1[0]) && isInterleave(s1.substr(1), s2, s3.substr(1));
        }
        return ((s3[0] == s2[0]) && isInterleave(s1, s2.substr(1), s3.substr(1))) ||
                 ((s3[0] == s1[0]) && isInterleave(s1.substr(1), s2, s3.substr(1)));
    
    }
};

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    Solution s;
    printf("is_interleave=%d\n", s.isInterleaveV2(s1, s2, s3));
    s3 = "aadbbbaccc";
    printf("is_interleave=%d\n", s.isInterleaveV2(s1, s2, s3));
}

/**
Problem: Distinct Subsequences 

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Hide Tags Dynamic Programming String

 */
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.length() == 0 || T.length() == 0 || S.length() < T.length()) {
            return 0;
        }
        vector<vector<int> > flag(S.length(), vector<int>(T.length(), 0));
        for (int i = 0; i < S.length(); i++) {
            for (int j = 0; j < T.length(); j++) {
                if (i == 0) {
                    flag[i][j] = (j == 0 && S[i] == T[j]) ? 1 : 0;
                } else {
                    flag[i][j] = flag[i-1][j];
                    if (S[i] == T[j]) {
                        int addition = j == 0 ? 1 : flag[i-1][j-1];
                        flag[i][j] += addition;
                    }
                }
            }
        }
        return flag[S.length()-1][T.length()-1];    
    }
};

int main() {
    string S = "rabbbit";
    string T = "rabbit";
    Solution s;
    int d = s.numDistinct(S, T);
    printf("d=%d\n", d);
    
}

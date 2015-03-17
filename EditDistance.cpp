/**
 * =====================================================================================
 *       Filename:  EditDistance.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
Hide Tags Dynamic Programming String

解题思路：
经典的编辑距离算法，动态规划，ed[i][j] = min(ed[i-1][j]+1, ed[i][j-1]+1, ed[i-1][j-1]+(word1[i]!=word2[j]))
注意""和有内容的串的情况，初始化的时候二维数组行列都要比word1和word2的长度分别大1,以便处理这种情况，同时也方便后面的计算
时间复杂度O(n^2)
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > ed;
        vector<int> init_line;
        for (int i = 0; i < word2.length() + 1; i++) {
            init_line.push_back(i);
        }
        ed.push_back(init_line);
        for (int i = 0; i < word1.length(); i++) {
            vector<int> one_line;
            one_line.push_back(i+1);
            ed.push_back(one_line);
            for (int j = 0; j < word2.length(); j++) {
                int temp = word1[i] == word2[j] ? 0 : 1;
                int new_ed = ed[i][j] + temp < ed[i][j+1] + 1 ? ed[i][j] + temp : ed[i][j+1] + 1;
                new_ed = new_ed < ed[i+1][j] + 1 ? new_ed : ed[i+1][j] + 1;
                ed[i+1].push_back(new_ed);
            }
        }
        return ed[word1.length()][word2.length()];
    }
};

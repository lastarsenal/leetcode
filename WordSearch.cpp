/*
 * =====================================================================================                                                                                                                                                    
 *
 *       Filename:  WordSearch.cpp
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

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
Hide Tags Array Backtracking

*/

#include <stdio.h>
#include <vector>
#include <string>
#include <set>

using namespace std;


class Solution {
private:
    static int direct[4][2];
    
    bool check(vector<vector<char> > &board, const string& word, vector<vector<bool> > &visit, int i, int j, int k) {
        visit[i][j] = true;
        if (board[i][j] == word[k]) {
            if (k == word.length() - 1) {
                return true;
            }
            for (int d = 0; d < 4; d++) {
                int next_i = i + direct[d][0];
                int next_j = j + direct[d][1];
                if (next_i >= 0 && next_i < board.size()
                        && next_j >= 0 && next_j < board[i].size()
                        && !visit[next_i][next_j]) {
                    bool is_exist = check(board, word, visit, next_i, next_j, k+1);
                    if (is_exist) {
                        return true;
                    }
                }
            }
        }
        visit[i][j] = false;
        return false;
    } 
    
public:
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<bool> > visit;
        visit.resize(board.size());
        for (int i = 0; i < visit.size(); i++) {
            visit[i].resize(board[i].size(), false);
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                bool is_exist = check(board, word, visit, i, j, 0);
                if (is_exist) {
                    return true;
                }
            }
        }
        return false;      
    }
};

int Solution::direct[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

int main() {
    char board[3][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    vector<vector<char> > board_vec;
    for (int i = 0; i < 3; i++) {
        vector<char> line;
        for (int j = 0; j < 4; j++) {
            line.push_back(board[i][j]);
        }
        board_vec.push_back(line);
    }
    Solution s;
    string word = "ABCCED";
    bool exist = s.exist(board_vec, word);
    printf("str=%s, exist=%d\n", word.c_str(), exist);
    word = "SEE";
    exist = s.exist(board_vec, word);
    printf("str=%s, exist=%d\n", word.c_str(), exist);
    word = "ABCB";
    exist = s.exist(board_vec, word);
    printf("str=%s, exist=%d\n", word.c_str(), exist);
}

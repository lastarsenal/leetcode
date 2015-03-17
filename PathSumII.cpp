/**
 * =====================================================================================
 *       Filename:  PathSumII.cpp
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

Problem: Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
Hide Tags Tree Depth-first Search

解题思路：递归，前序遍历，然后把结果保存在vector中返回
 */

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        int remain = sum - root->val;
        if (remain == 0 && root->left == NULL && root->right == NULL) {
            vector<int> temp;
            temp.push_back(root->val);
            result.push_back(temp);
            return result;
        }
        if (root->left) {
            vector<vector<int> > left_res = pathSum(root->left, remain);
            for (int i = 0; i < left_res.size(); i++) {
                left_res[i].insert(left_res[i].begin(), root->val);
                result.push_back(left_res[i]);
            }
        }
        if (root->right) {
            vector<vector<int> > right_res = pathSum(root->right, remain);
            for (int i = 0; i < right_res.size(); i++) {
                right_res[i].insert(right_res[i].begin(), root->val);
                result.push_back(right_res[i]);
            }
        }
        return result;
    }
};

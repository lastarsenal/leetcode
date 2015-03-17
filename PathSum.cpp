/**
 * =====================================================================================
 *       Filename:  PathSum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Problem: Path Sum 
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Hide Tags Tree Depth-first Search

解题思路：
前序遍历递归程序，算和
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        int remain = sum - root->val;
        if (remain == 0 && root->left == NULL && root->right == NULL) {
            return true;
        }
        bool hasLeftSum = false;
        if (root->left) {
            hasLeftSum = hasPathSum(root->left, remain);
        }
        if (hasLeftSum) {
            return true;
        }
        if (root->right) {
            return hasPathSum(root->right, remain);
        }
        return false;
    }

    bool hasPathSumV2(TreeNode *root, int sum) {
        if (root == NULL) return false;
        vector<TreeNode*> stack;
        stack.push_back(root);
        vector<int> sum_stack;
        sum_stack.push_back(sum);
        while (!stack.empty()) {
            TreeNode *node = stack.back();
            stack.pop_back();
            int cur_sum = sum_stack.back();
            sum_stack.pop_back();
            int remain = cur_sum - node->val;
            if (remain == 0 && node->left == NULL && node->right == NULL) {
                return true;
            }
            if (node->right) {
                sum_stack.push_back(remain);
                stack.push_back(node->right);
            }
            if (node->left) {
                sum_stack.push_back(remain);
                stack.push_back(node->left);
            }
        }
        return false;
    }
};

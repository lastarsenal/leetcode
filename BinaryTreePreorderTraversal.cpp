/**
 * =====================================================================================
 *       Filename:  WordSearch.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Problem: Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Hide Tags Tree Stack

 */

#include <vector>
#include <stdlib.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
         TreeNode *p = root;
         vector<TreeNode*> traverse_stack;
         vector<int> result;
         if (p != NULL) {
             traverse_stack.push_back(p);
             while (!traverse_stack.empty()) {
                 TreeNode* p = traverse_stack.back();
                 traverse_stack.pop_back();
                 result.push_back(p->val);
                 if (p->right != NULL) {
                     traverse_stack.push_back(p->right);
                 }
                 if (p->left != NULL) {
                     traverse_stack.push_back(p->left);
                 }
             }
         }        
         return result;
    }
};

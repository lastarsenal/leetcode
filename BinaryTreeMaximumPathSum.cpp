/**
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

Hide Tags Tree Depth-first Search

解题思路：
这道题大面上是递归的方法，但有一个trick，就是需要使用一个成员变量，在递归的过程中全局性的记录最大路径和。
原因是最大路径不一定是经过树的根节点的，但是一定是经过某一个子树的根节点。所以全局记录可以处理这种情况。
函数maxPathSumThroughRoot(TreeNode *root)专门用来返回以根节点为起始点的最大路径，而在此之前，可以全局记录可能出现的最大路径。
1. 最大路径max_sum = max(root->val, root->val+leftSum, root->val+rightSum, root->val+leftSum+rightSum, leftSum ,rightSum)，有6种可能；
2. 以根节点为起点，是为了顺利的递归每一层，root_sum = max(root->val, root->val+leftSum, root->val+rightSum)，
   三种情况，注意这里和1中max_sum的不同 
maxPathSumThroughRoot(TreeNode *root)就干上面两件事，最终结果保存在max_sum中，接口函数则直接调maxPathSumThroughRoot，最后返回max_sum即可。
 */

#include <limits.h>
#include <stdio.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    int max_sum;
    
    int maxPathSumThroughRoot(TreeNode *root) {
        if (root == NULL) {
            return INT_MIN;
        }
        //1. 全局记录max_sum
        int leftSum = -1;
        int pathSum = root->val;
        if (root->left != NULL) {
            leftSum = maxPathSumThroughRoot(root->left);  
            if (leftSum > 0) {
                pathSum += leftSum;
            }
        }
        int rightSum = -1;
        if (root->right != NULL) {
            rightSum = maxPathSumThroughRoot(root->right);
            if (rightSum > 0) {
                pathSum += rightSum;
            }
        }
        //cur_max当前已经是max(root->val, root->val+leftSum, root->val+rightSum, root->val+leftSum+rightSum)
        int cur_max = pathSum;
        //接下来计算cur_max=max(cur_max, leftSum, rightSum),这样六种情况找max完成
        if (root->left != NULL) {
            cur_max = cur_max > leftSum ? cur_max : leftSum;
        }
        if (root->right != NULL) {
            cur_max = cur_max > rightSum ? cur_max : rightSum;
        }
        if (cur_max > max_sum) {
            max_sum = cur_max;
        }
        //2. 计算以root为起点的最大路径，用于递归的计算
        //root_sum=(root->val, root->val+leftSum, root->val+rightSum)
        int root_sum = root->val > root->val + leftSum ? root->val : (root->val + leftSum);
        root_sum = root_sum > root->val + rightSum ? root_sum : (root->val + rightSum);
        return root_sum;
    }

public:
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        maxPathSumThroughRoot(root);
        return max_sum;
    }
};

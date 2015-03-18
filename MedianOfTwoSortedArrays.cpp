/**
 * =====================================================================================
 *       Filename:  MedianOfTwoSortedArrays.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Hide Tags Divide and Conquer Array Binary Search
解题思路：
1. 这道题并不是传统的二分，而是在两个已排序数组中，根据找第k大数的函数，迭代寻找，同时要记得更新k
2. 总是把A设定为较短的数组，如果不是，就调用函数倒一下
3. 在A中查看A[k/2-1]的位置，B中查看B[k-(k/2-1)]的位置，如果A[k/2-1] < B[k/2]，则至少有k/2个数<=B[k/2)],可以舍弃掉A的前半段，从而在A的后半段和B中寻找k/2大的数。同样道理，当A[k/2-1] > B[k/2]时，B的前半段可以舍掉，在A和B的后半段中寻找k/2大的数
4. 如果A[k/2-1] == B[k/2]，则找到，可以直接返回；
5. 计算k/2时，需要跟较短的数组A的长度m比较，取两者较小，如果m < k/2，则3中的数字要随着变化一下
6. 如果A和B中元素个数加起来是偶数，则中位数要是两个中间数字之和的平均值，所以调用找k大函数时，要对偶数注意一下处理
 */

#include <stdio.h>
#include <stdlib.h>

class Solution {
private:
    double findKth(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return findKth(B, n, A, m, k);    
        } else if (m == 0) {
            return B[k-1];
        } else if (k == 1) {
            return A[0] < B[0] ? A[0] : B[0];
        }    
        int pa = k/2 < m ? k/2 : m;
        int pb = k - pa;
        if (A[pa-1] < B[pb-1]) {
            return findKth(A+pa, m-pa, B, n, k-pa);
        } else if (A[pa-1] > B[pb-1]) {
            return findKth(A, m, B+pb, n-pb, k-pb);
        } else {
            return A[pa-1];
        }
    
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2 == 1) { 
            return findKth(A, m, B, n, total / 2 + 1);
        } else {
            return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
        }
    }
};

/*
 * =====================================================================================                                                                                                                                                    
 *
 *       Filename:  WordSortedArray.cpp
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

==Problem==

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

Hide Tags Array Two Pointers

==Solve==
两个数组分别从后向前扫，比较后把正确的数放在A数组末尾。这样就不用挪动太多位置了。

*/

#include <stdio.h>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int ia = m-1;
        int ib = n-1;
        int ic = m+n-1;
        while (ib >= 0) {
            if (ia < 0 || A[ia] <= B[ib]) {
                A[ic] = B[ib];
                ib--;
            } else {
                A[ic] = A[ia];
                ia--;
            }
            ic--;
        }
    }
};

int main() {
    int a[11] = {1, 4, 5, 7, 9};
    int b[6] = {2, 3, 6, 7, 8, 10};
    Solution s;
    s.merge(a, 5, b, 6);
    for (int i=0; i<11; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

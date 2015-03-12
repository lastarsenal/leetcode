/**
 * =====================================================================================
 *       Filename:  RotateArray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-012
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

[Problem] Rotate Array:

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Hide Tags Array

 */


#include <stdio.h>

class Solution {
private:
    void reverse(int nums[], int i, int j) {
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        } 
    }
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};

int main() {
    int nums[7] = {1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotate(nums, 7, 3);
    for (int i = 0; i < 7; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 * =====================================================================================                                                                                                                                                    
 *
 *       Filename:  FindMinII.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Find Minimum in Rotated Sorted Array II   

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

Hide Tags Array Binary Search

 */

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;
        int min = num[left];
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid != left && mid != right) {
                if (num[mid] > num[left]) {
                    if (num[mid] > num[right]) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                
                } else if (num[mid] == num[left]) {
                    if (num[mid] > num[right]) {
                        left = mid;
                    } else if (num[mid] == num[right]) {
                        for (int j=left+1; j <= right; j++) {
                            if (num[j] < min) {
                                min = num[j];
                            }
                        }
                        break;
                    }
                    else {
                        right = mid;
                    }
                } else {
                    if (num[mid] > num[right]) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                }
            } else {
                min = num[left] < num[right] ? num[left] : num[right];
                break;  
            }
        }
        return min;     
    }
};

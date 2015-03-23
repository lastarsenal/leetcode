#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() <= 1) {
            return 0;
        }     
        int start = 0;
        int end = height.size() - 1;
        int max_area = 0;
        while (start < end) {
            int min_height = height[start] < height[end] ? height[start] : height[end];
            int area = min_height * (end - start);
            if (area > max_area) {
                max_area = area;
            }
            if (height[start] < height[end]) {
                int j = start + 1;
                while (j < end && height[j] <= height[start]) {
                    j++;
                }
                start = j;
            } else {
                int j = end - 1;
                while (j > start && height[j] <= height[end]) {
                    j--;
                }
                end = j;
            }
        }
        return max_area;
    }
};


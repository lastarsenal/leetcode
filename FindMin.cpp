#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;
        int min = num[left];
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid != left && mid != right) {
                if (num[mid] < num[left] && num[mid] < num[right]) {
                    right = mid;
                } else if (num[mid] > num[left] && num[mid] > num[right]) {
                    left = mid;
                } else if (num[mid] > num[left] && num[mid] < num[right]) {
                    min = num[left];
                    break;
                }
            } else {
                min = num[left] < num[right] ? num[left] : num[right];
                break;  
            }
        }
        return min;
    }
};

int main() {
    Solution s;
    vector<int> num;
    int a[7] = {4, 5, 6, 7, 0, 1, 2};
    for (int i=0; i < 7; i++) {
        num.push_back(a[i]);
    }
    int min = s.findMin(num);
    printf("min=%d\n", min);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int min_gap = INT_MAX;
        int min_sum = 0;
        for (int i = 0; i < num.size(); i++) {
            int j = i+1;
            int k = num.size() - 1;
            while (j < k) {
                if (j > i+1 && num[j] == num[j-1]) {
                    j++;
                    continue;
                }
                if (k < num.size() - 1 && num[k] == num[k+1]) {
                    k--;
                    continue;
                }
                int sum = num[i] + num[j] + num[k];
                int gap = abs(target - sum);
                if (gap == 0) {
                    return sum;
                }
                if (gap < min_gap) {
                    min_gap = gap;
                    min_sum = sum;
                }
                if (target < sum) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return min_sum;
    }
};

int main() {
    Solution s;
    int test_case[3] = {0, 1, 2};
    int target = 3;
    vector<int> num;
    for (int i = 0; i < 3; i++) {
        num.push_back(test_case[i]);
    }
    int gap = s.threeSumClosest(num, target);
    printf("cloasest gap=%d\n", gap);
}


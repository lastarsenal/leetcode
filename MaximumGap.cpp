#include <vector>
#include <stdio.h>
#include <limits.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) {
            return 0;
        }
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] > max_val) {
                max_val = num[i];
            }
            if (num[i] < min_val) {
                min_val = num[i];
            }
        }

        int gap = (int)ceil(double(max_val - min_val) / (num.size() - 1));
        int bucket_num = ((max_val - min_val) / gap) + 1;
        vector<int> bucket_starts;
        vector<int> bucket_ends;
        bucket_starts.resize(bucket_num, max_val);
        bucket_ends.resize(bucket_num, min_val);
        for (int  i = 0; i < num.size(); i++) {
            if (num[i] == max_val || num[i] == min_val) {
                continue;
            }
            int bucket_idx = (num[i] - min_val) / gap;
            if (num[i] < bucket_starts[bucket_idx]) {
                bucket_starts[bucket_idx] = num[i];
            }
            if (num[i] > bucket_ends[bucket_idx]) {
                bucket_ends[bucket_idx] = num[i];
            }
        }
        int prev = min_val;
        int max_gap = 0;
        for (int i = 0; i < bucket_num; i++) {
            if (bucket_starts[i] == max_val || bucket_ends[i] == min_val) {
                continue;
            }
            int gap = bucket_starts[i] - prev;
            if (gap > max_gap) {
                max_gap = gap;
            }
            prev = bucket_ends[i];
        }
        if (max_val - prev > max_gap) {
            max_gap = max_val - prev;
        }
        return max_gap;
    }
};

int main() {
    int test[] = {3, 10, 5, 7, 6, 8, 4, 2};
    vector<int> num(test, test + sizeof(test) / sizeof(int) );
    Solution s;
    int max_gap = s.maximumGap(num);
    printf("max_gap=%d\n", max_gap);
}

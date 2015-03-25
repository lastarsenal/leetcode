#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int sum = 0;
        int prev = 0;
        for (int i = 0; i < ratings.size(); i++) {
            int cur = 1;
            if (i - 1 >= 0 && ratings[i] > ratings[i-1]) {
                cur = prev + 1; 
            }
            if (i + 1 < ratings.size() && ratings[i] > ratings[i+1] && cur < 2) {
                cur = 2;
            }
            sum += cur;
            prev = cur;
        }
        return sum;      
    }
};

int main() {
    int rate_arr[] = {2,7,4,4,5,6,4};
    vector<int> ratings(rate_arr, rate_arr + sizeof(rate_arr) / sizeof(int) );
    Solution s;
    int sum = s.candy(ratings);
    printf("candy number=%d\n", sum);
}

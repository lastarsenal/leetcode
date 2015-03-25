#include <string>
#include <stdio.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int atoi(string str) {
        bool is_positive = true;
        bool is_meat_sign = false;
        bool is_start = false;
        int res = 0;
        int limit = INT_MAX;
        for (int i = 0; i < str.length(); i++) {
            if (!is_start) {
                if  (str[i] == ' ') {
                    continue;
                } else {
                    is_start = true;
                }
            } else if (str[i] == ' '){
                break;
            }
            if (str[i] == '-') {
                is_positive = false;
                limit = INT_MIN;
            }
            bool is_sign = str[i] == '+' || str[i] == '-';
            if (is_sign) {
                if (is_meat_sign) {
                    break;
                } else {
                    is_meat_sign = true;
                    continue;
                }
            }
            if (str[i] >= '0' && str[i] <= '9') {
                int val = str[i] - '0';
                if (!is_positive) {
                    val = -val;
                }
                if (res == 0) {
                    res = val;
                } else {
                    bool is_not_overflow = (is_positive && (limit - val)/10 >= res) || (!is_positive && res >= (limit-val)/10);
                    if (is_not_overflow) {
                        res = res * 10 + val;
                    } else {
                        res = limit;
                        break;
                    }
                }
            } else {
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "   2345";
    int val = s.atoi(str);
    printf("%d\n", val);
    str = "   +2345";
    val = s.atoi(str);
    printf("%d\n", val);
    str = "   -2345";
    val = s.atoi(str);
    printf("%d\n", val);
    str = "   --2345";
    val = s.atoi(str);
    printf("%d\n", val);
    str = "   +0 123";
    val = s.atoi(str);
    printf("%d\n", val);
    str = "-2147483648";
    val = s.atoi(str);
    printf("%d\n", val);
}

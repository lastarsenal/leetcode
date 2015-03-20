#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        int unit_len = nRows + nRows - 2;
        int step = s.length() / unit_len;
        int remain = s.length() % unit_len;
        if (remain > 0) {
            step += 1;
        }  
        string res = "";
        for (int i = 0; i < nRows; i++) {
            int offset = unit_len - i;
            bool is_follow = offset < unit_len && offset >= nRows;
            for (int j = 0; j < step; j++) {
                int idx = i + j * unit_len;
                if (idx < s.length()) {
                    res += s[idx];
                } else {
                    break;
                }
                if (is_follow) {
                    idx = offset + j * unit_len;
                    if (idx < s.length()) {
                        res += s[idx];
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "PAYPALISHIRING";
    string res = s.convert(str, 3);
    printf("%s\n", res.c_str());
    res = s.convert(str, 2);
    printf("%s\n", res.c_str());
}

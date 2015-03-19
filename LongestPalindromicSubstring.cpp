#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool> > flag;
        int max_len = 0;
        int start = 0;
        for (int step = 0; step < s.length(); step++) {
            for (int i = 0; i < s.length() - step; i++) {
                if (step == 0) {
                    vector<bool> one_line;
                    one_line.resize(s.length());
                    flag.push_back(one_line);              
                }
                flag[i][i+step] = s[i] == s[i+step];
                if (step > 1 && flag[i][i+step]) {
                    flag[i][i+step] = flag[i+1][i+step-1];
                } 
                if (flag[i][i+step] && step + 1 > max_len) {
                    max_len = step + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);          
    }
};

int main() {
    string str = "babcbabcbaccba";
    Solution s;
    string ret = s.longestPalindrome(str);
    printf("ret=%s\n", ret.c_str());
}

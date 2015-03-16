/**
 * =====================================================================================
 *       Filename:  ReoderList.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Hide Tags Backtracking String

解题思路：实际上是找到一个合法的切分，每一个字符都要参与，不能省略0，如果出现'00'在ip的某一段中，则不合法。
考虑010010，有两种切分：0.10.0.10, 0.100.1.0

 */

#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {

private:
    vector<string> getValidIpSeg(string s, int seg_num) {
        vector<string> results;
        if (s.length() == 0) {
            return results;
        }
        if (seg_num == 1) {
            if (s.length() > 1 && s[0] == '0') {
                return results;
            }
            int val = atoi(s.c_str());
            if (val >= 0 && val <= 255) {
                results.push_back(s);
            }
            return results;
        } else {
            for (int i = 1; i <= 3 && i < s.length(); i++) {
                string part = s.substr(0, i);
                if (i > 1 && part[0] == '0') {
                    continue;
                }
                int val = atoi(part.c_str());
                if (val >= 0 && val <= 255) {
                    //printf("try %s, suffix=%s, seg_num=%d\n", part.c_str(), s.substr(i).c_str(), seg_num);
                    vector<string> suffix_res = getValidIpSeg(s.substr(i), seg_num - 1);
                    for (int j = 0; j < suffix_res.size(); j++) {
                        results.push_back(part + "." + suffix_res[j]);
                    }
                }
            }
            return results;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        return getValidIpSeg(s, 4);       
    }
};

int main() {
    Solution s;
    string str = "010010";
    vector<string> resIp = s.restoreIpAddresses(str);
    for (int i = 0; i < resIp.size(); i++) {
         printf("%s\n", resIp[i].c_str());
    }
}

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        }
        string common_str = "";
        int i = 0;
        while (true) {
            bool is_same = true;
            if (i >= strs[0].length()) {
                break;
            }
            char target = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != target) {
                    is_same = false;
                    break;
                }
            }
            if (is_same) {
                common_str += target;
            } else {
                break;
            }
            i++;
        }
        return common_str;
        
    }
};

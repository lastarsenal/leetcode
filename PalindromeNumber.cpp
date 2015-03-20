#include <stdio.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        }
        int y = x;
        int div = 1;
        while (y >= 10) {
             y = y / 10;
             div *= 10;
        }      
        while (div > 1) {
            int head = x / div;
            int tail = x % 10;
            if (head != tail) {
                return false;
            }
            x = (x - (head * div)) / 10;
            div /= 100;
        }
        return true;
    }
};

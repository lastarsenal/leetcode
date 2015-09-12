/****************************
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
******************************/

class Solution {
public:
    int titleToNumber(string s) {
        int base = 26;
        int coef = 1;
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            int k = s[s.length() - i - 1] - 'A' + 1;
            num += k * coef;
            coef *= base;
        }   
        return num;   
    }
};

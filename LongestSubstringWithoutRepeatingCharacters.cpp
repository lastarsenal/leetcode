/**

 * =====================================================================================
 *       Filename:  LongestSubstringWithoutRepeatingCharacters.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Problems: Longest Substring Without Repeating Characters 

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Hide Tags Hash Table Two Pointers String


解题思路：
1. 动态规划：
   设len[i]是以s[i]结尾的无重复字符的最长子串，则：
      len[i] = len[i-1]+1(当s[i]没有在之前出现过)或者 = i+1-char_pos[s[i]](如果s[i]在之前出现过，
               且char_pos[s[i]]记录的是前面最近的s[i]出现位置)
      同时注意更新最长子串的起始位置start.（start和当前扫到的位置i即为双指针）
   遍历字符串的每一个位置，记录max_len即可
2. 因为字符串每个字符都是ASCII码，所以用256长的定长数组记录,相当于题目提示中的hashtable了。
3. 注意更新最长无重复字符子串的起始位置，这个起始位置用于判断char_pos[s[i]]是否有效。
注意testcase: abba, len=2（没有上面第3的话，这个例子会计算成3，因为a的char_pos在最后遇到a时有效，按1减长度就是3了，
事实上，这时满足条件的最长子串起始位置已经变更了，第一个a出现的位置在起始位置之前，即从起始位置之后没有出现过，
cur_len应该直接+1，而不是更新到两个位置之间的间隔）; vqblqcb, len=4（如无3的判断，则会输出5，答案是4，就不对了）
 */

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int char_pos[256] ={0};//初始化为0，表示所有字符都没有出现过
        int cur_len = 0;
        int max_len = 0;
        int start = 1;
        for (int i = 0; i < s.length(); i++) {
             //出现过且最近出现的位置在最长子串的起始位置之后，方才有效，重新计算cur_len，并更新start
             if (char_pos[s[i]] > 0 && char_pos[s[i]] >= start) {
                 cur_len = i+1-char_pos[s[i]];
                 start = char_pos[s[i]]+1;
             } else {
                 cur_len++;
             }
             char_pos[s[i]] = i+1;
             if (max_len < cur_len) {
                 max_len = cur_len;
             }
        }
        return max_len;    
    }
};

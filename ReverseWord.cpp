/*
 * =====================================================================================                                                                                                                                                    
 *
 *       Filename:  ReverseWord.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================
 *
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
Hide Tags String

 */


#include <iostream>
#include <string>

using namespace std;

void reverseWords(string& s) {
    cout << "replace[before] [" << s << "]" << endl;
    char space = ' ';
    s.erase(0, s.find_first_not_of(space));
    s.erase(s.find_last_not_of(space) + 1);
    size_t tail_pos = s.length() - 1;
    size_t head_pos = 0;
    while (true) {
        size_t tail_idx = s.rfind(space, tail_pos);
        size_t head_idx = s.find(space, head_pos);
        if (tail_idx != string::npos && head_idx != string::npos && tail_idx >= head_idx) {
            string tail_word = s.substr(tail_idx + 1, tail_pos - tail_idx);
            string head_word = s.substr(head_pos, head_idx - head_pos);
            s.replace(head_pos, head_idx - head_pos, tail_word);
            int tail_off = tail_word.length() - (head_idx - head_pos);
            s.replace(tail_idx + 1 + tail_off, tail_pos - tail_idx, head_word);
            head_pos = head_idx + 1 + tail_off;
            int head_off = head_word.length() - (tail_pos - tail_idx);
            tail_pos = tail_idx - 1 - head_off;
            size_t erase_r = s.find_last_not_of(space, tail_pos) + 1;
            size_t right_len = tail_pos - erase_r + 1; 
            s.erase(erase_r, right_len);
            tail_pos -= right_len;
            size_t left_len = s.find_first_not_of(space, head_pos) - head_pos;
            s.erase(head_pos, left_len);
            tail_pos -= left_len;
        } else {
            break;
        }
    }
    cout << "replace[after] [" << s << "]" << endl;
}

void reverseWordsV2(string &s) {
    cout << "replace[before] [" << s << "]" << endl;
    char space = ' ';
    size_t head_pos = 0;
    while (head_pos != string::npos) {
        size_t len = s.find_first_not_of(space, head_pos) - head_pos;
        len = head_pos > 0 ? len - 1 : len;
        s.erase(head_pos, len);
        head_pos = s.find(space, head_pos + 1);
    }
    size_t tail_pos = s.length() - 1;
    head_pos = 0;
    while (true) {
        size_t tail_idx = s.rfind(space, tail_pos);
        size_t head_idx = s.find(space, head_pos);
        if (tail_idx != string::npos && head_idx != string::npos && tail_idx >= head_idx) {
            string tail_word = s.substr(tail_idx + 1, tail_pos - tail_idx);
            string head_word = s.substr(head_pos, head_idx - head_pos);
            s.replace(head_pos, head_idx - head_pos, tail_word);
            int tail_off = tail_word.length() - (head_idx - head_pos);
            s.replace(tail_idx + 1 + tail_off, tail_pos - tail_idx, head_word);
            head_pos = head_idx + 1 + tail_off;
            int head_off = head_word.length() - (tail_pos - tail_idx);
            tail_pos = tail_idx - 1 - head_off;
        } else {
            break;
        }
    }
    cout << "replace[after] [" << s << "]" << endl;
}

int main() {
    string str = "what a happy day";
    reverseWordsV2(str);
    
    str = "what an another happy day";
    reverseWordsV2(str);
    
    
    str = " what a happy day";
    reverseWordsV2(str);
    
    str = "what a happy day  ";
    reverseWordsV2(str);
    
    str = " what a happy day   ";
    reverseWordsV2(str);
    
    str = " what a  happy day   ";
    reverseWordsV2(str);

    str = " what    an            another  happy    day   ";
    reverseWordsV2(str);
}


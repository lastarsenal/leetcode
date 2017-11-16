/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(int* numbers, int len, int target) {
            vector<int> result;
            unordered_map<int, int> mymap;
            int index1, index2;
            index1 = 0;
            index2 = 0;
            for (int i=0; i<len; i++) {
                if (mymap.find(numbers[i]) == mymap.end()) {
                    mymap[target-numbers[i]] = i;
                } else {
                    index1 = ((mymap[numbers[i]] < i) ? mymap[numbers[i]] : i) + 1;
                    index2 = ((mymap[numbers[i]] > i) ? mymap[numbers[i]] : i) + 1;
                    result.push_back(index1);
                    result.push_back(index2);
                    break;
                }
            }
            return result;
        }
};

int main() {
    Solution s;
    int a[4]={2,11,13,7};
    vector<int> r = s.twoSum(a, 4, 9);
    for (int i = 0; i < r.size(); i++) {
        printf("%d\n", r[i]);
    }
}

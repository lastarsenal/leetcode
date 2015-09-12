/*****************************
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
******************************/
#include <set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> num_set;
        for (int i = 0; i < nums.size(); i++) {
            if (num_set.find(nums[i]) != num_set.end()) {
                return true;
            }
            num_set.insert(nums[i]);
        }
        return false;
    }
};

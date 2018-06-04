/* Problem:
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use th same element twice.

    Example:
        Given nums = [2, 7, 11, 15], target = 9,
        Because nums[0] + nums[1] = 2 + 7 = 9,
        return [0, 1]
*/
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes(2);
        vector<pair<int, int>> extend_nums(nums.size());
        for (int i=0; i<nums.size(); i++) {
            extend_nums[i] = pair<int, int>(nums[i], i);
        }
        sort(extend_nums.begin(), extend_nums.end(), cmp);

        int i=0, j=extend_nums.size()-1, sum;
        while ((sum = extend_nums[i].first + extend_nums[j].first) != target) {
            if (sum > target) {
                j--;                
            } else {
                i++;
            }
        }

        indexes[0] = extend_nums[i].second;
        indexes[1] = extend_nums[j].second;
        return indexes;
    }
};

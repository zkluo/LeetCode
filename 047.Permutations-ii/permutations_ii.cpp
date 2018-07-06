/*
 * 与046方法同
 * Author: Luo Zhikun
 * Date: 2018/7/6
 */

bool isDecrease(vector<int>& nums) {
    int first = nums[0];
    for (int i=1; i<nums.size(); i++) {
        if (nums[i] > first) {
            return false;
        }
        first = nums[i];
    }
    return true;
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size () == 0) 
            return result;
        if (nums.size() == 1) {
            result.push_back(nums);
            return result;
        }
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        while (!isDecrease(nums)) {
            int i = 0;
            for (i=nums.size()-1; i>=1; i--) {
                if (nums[i-1] < nums[i]) {
                    break;
                }
            } 
            int dif = nums[i] - nums[i-1];
            int c_j = i;
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[j] > nums[i-1] && nums[j] - nums[i-1] < dif) {
                    dif = nums[j] - nums[i-1];
                    c_j = j;
                }
            }
            int temp = nums[c_j];
            nums[c_j] = nums[i-1];
            nums[i-1] = temp;
            sort(nums.begin()+i, nums.end());
            result.push_back(nums);
        }
        return result;
    }
};
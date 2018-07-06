/*
 * 我使用了字符串遍历的非递归算法
 * Date: 2018/7/6
 * Author: Luo Zhikun
 */

bool isDecrease(vector<int>& nums) {
    int start = nums[0];
    for (int i=1; i<nums.size(); i++) {
        if (nums[i] > start) {
            return false;
        }
        start = nums[i];
    }
    return true;
}

class Solution {
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0)
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
                if (nums[i-1] < nums[i])
                break;
            }
            int min_gap = nums[i] - nums[i-1];
            int closest_j = i;
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[j] > nums[i-1] && nums[j] - nums[i-1] < min_gap) {
                    min_gap = nums[j] - nums[i-1];
                    closest_j = j;
                }
            }
            int temp = nums[closest_j];
            nums[closest_j] = nums[i-1];
            nums[i-1] = temp;
            sort(nums.begin() + i, nums.end());
            result.push_back(nums);
        }
        return result;
    }
};

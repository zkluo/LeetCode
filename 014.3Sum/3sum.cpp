/*用时7分钟*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        sort(nums.begin(), nums.end());
        for (int i=0; nums[i]<=0; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int m = i+1, n = nums.size()-1;
            while (m < n) {
                int sum = nums[m] + nums[n];
                if (sum > -nums[i]) {
                    n--;
                } else if (sum < -nums[i]) {
                    m++;
                } else {
                    vector<int> temp = {nums[i], nums[m], nums[n]};
                    res.push_back(temp);
                    int temp_m = m, temp_n = n;
                    while (nums[temp_m] == nums[m] && nums[temp_n] == nums[n]) {
                        m++;
                        n--;
                    }
                }
            }
        }
        return res;
    }
};
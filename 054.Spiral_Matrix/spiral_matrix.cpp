/*
 * 打印螺旋数组, 简单
 * Author: Luo Zhikun
 * Date: 2018/7/7
 */

class Solution {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
        if (matrix.size() == 1) {
            return matrix[0];
        }
        vector<vector<bool>> flag(matrix.size(), vector<bool>(matrix[0].size(), true));
        int state = 0;
        int i = 0, j = 0;
        while (result.size() < matrix.size() * matrix[0].size()) {
            if (flag[i][j]) {
                result.push_back(matrix[i][j]);
                flag[i][j] = false;
            }
            if (state == 0) {
                j++;
                if (j >= matrix[0].size() || flag[i][j] == false) {
                    j--;
                    i++;
                    state = 1;
                }
            } else if (state == 1) {
                i++;
                if (i >= matrix.size() || flag[i][j] == false) {
                    i--;
                    j--;
                    state = 2;
                }
            } else if (state == 2) {
                j--;
                if (j < 0 || flag[i][j] == false) {
                    j++;
                    i--;
                    state = 3;
                }
            } else {
                i--;
                if (i < 0 || flag[i][j] == false) {
                    i++;
                    j++;
                    state = 0;
                }
            }
        }
        return result;
    }
};

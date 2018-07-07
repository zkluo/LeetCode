/*
 * 和Spiral Matrix没什么区别
 * Author: Luo Zhikun
 * Date: 2018/7/7
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        if (n == 0) {
            return result;
        }
        if (n == 1) {
            result[0][0] = 1;
            return result;
        }
        vector<vector<bool>> flag(n, vector<bool>(n, true));
        int state = 0;
        int num = 1;
        int i = 0, j = 0;
        while (num <= n * n) {
            if (flag[i][j]) {
                result[i][j] = num;
                num++;
                flag[i][j] = false;
            }
            if (state == 0) {
                j++;
                if (j >= result[0].size() || flag[i][j] == false) {
                    j--;
                    i++;
                    state = 1;
                }
            } else if (state == 1) {
                i++;
                if (i >= result.size() || flag[i][j] == false) {
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

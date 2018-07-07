/*
 * 字符串全排列遍历问题
 * Author: Luo Zhikun
 * Date: 2018/7/7
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> list(n, 0);
        for (int i=1; i<=n; i++) {
            list[i-1] = i;
        }
        int index = 1;
        for (;;) {
            if (index == k) {
                break;
            }
            int i = 0;
            for (i=list.size()-1; i>=1; i--) {
                if (list[i-1] < list[i]) {
                    break;
                }
            }
            int dif = list[i] - list[i-1];
            int c_j = i;
            for (int j=i+1; j<list.size(); j++) {
                if (list[j] > list[i-1] && list[j]-list[i-1] < dif) {
                    dif = list[j] - list[i-1];
                    c_j = j;
                }
            }
            int temp = list[i-1];
            list[i-1] = list[c_j];
            list[c_j] = temp;
            
            sort(list.begin()+i, list.end());
            index++;
        }
        string s = "";
        for (int i=0; i<list.size(); i++) {
            s = s + (char)(list[i]+'0');
        }
        return s;
    }
};

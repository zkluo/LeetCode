/*用时5分钟*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int i;
        for (i=0; i<strs[0].size(); i++) {
            bool flag = true;
            for (int j=1; j<strs.size(); j++) {
                if (i>=strs[j].size() || strs[j][i] != strs[0][i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                i--;
                break;
            }
        }
        return strs[0].substr(0, i+1);
    }
};
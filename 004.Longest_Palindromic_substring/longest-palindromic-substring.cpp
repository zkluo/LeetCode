class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) 
             return s; // s为空的时候不加这句话会超出时间限制！
        int left = 0, right = 0;
        int res_left = 0, res_right = 0;
        int len = 0;
        for (int i=0; i<s.size()-1; i++) {
            searchPalin(s, i, i, left, right);
            if (right - left + 1 > len) {
                len = right - left + 1;
                res_left = left;
                res_right = right;
            }
            searchPalin(s, i, i+1, left, right);
            if (right - left + 1 > len) {
                len = right - left + 1;
                res_left = left;
                res_right = right;
            }
        }
        return s.substr(res_left, res_right-res_left+1);
    }
   
    void searchPalin(string &s, int c_a, int c_b, int &left, int &right) {
        int i = 0;
        while (c_a-i>=0 && c_b+i<s.size() && s[c_a-i]==s[c_b+i]) {
            i++;
        }
        i--;
        left = c_a-i;
        right = c_b+i;
    }
};
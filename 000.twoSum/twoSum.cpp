///////////////////////////////////////////////////////////////////////////////
///  You should have received a copy of the GNU General Public License         
///  along with OST. If not, see <http://www.gnu.org/licenses/>.               
///                                                                            
///  @file     twoSum.cpp                                                       
///  @brief    No.1: Given an array of integers, return indices of the two numbers such that they add up to a specific target.
///            You may assume that each input would have exactly one solution, and you may not use the same element twice.  
///            Solution: 对输入数组按从小到大排序，创建两个指针分别指向排序后的数组的首尾，若此时两数之和>target，则尾指针向前移动一位； 
///            若此时两数之和<target，则头指针向后移动一位；若此时两数之和==target，则返回此时两个指针索引构成的数组                                                                          
///  @author   Zhikun Luo                                                                                                      
///  @version  1.0                                               
///  @date     2018.10.15                                                                               
///                                                                          
///////////////////////////////////////////////////////////////////////////////

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;    
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> index_nums(nums.size());
        for (int i=0; i<index_nums.size(); ++i) {
            index_nums[i] = pair<int, int>(i, nums[i]);
        }
        sort(index_nums.begin() ,index_nums.end(), cmp);
        vector<int> result(2);
        int i=0, j=index_nums.size()-1;
        while (i < j) {
            int sum = index_nums[i].second + index_nums[j].second;
            if (sum == target) {
                result[0] = index_nums[i].first < index_nums[j].first ? 
                    index_nums[i].first : index_nums[j].first;
                result[1] = index_nums[i].first < index_nums[j].first ? 
                    index_nums[j].first : index_nums[i].first;
                return result;
            } else if (sum < target) 
                i++;
            else
                j--;
        }
    }
};

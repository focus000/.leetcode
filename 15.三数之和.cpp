/*
 * @Author: liyunfang
 * @Date: 2020-01-18 22:38:39
 * @LastEditTime : 2020-01-19 16:48:15
 * @Description: 
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.91%)
 * Likes:    1709
 * Dislikes: 0
 * Total Accepted:    143.7K
 * Total Submissions: 572.8K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty()) return ret;
        sort(nums.begin(), nums.end());
        vector<size_t> pos{nums.size()-1};
        for (size_t j = 1; j < pos[0]; ++j)
        {
            pos.push_back(pos[j-1]);
            for (size_t i = 0; i < j; ++i)
            {
                if (j > 1 && nums[j] == nums[j-1]) i = j - 1;
                if (i && nums[i] == nums[i-1]) continue;
                if (pos[i] <= j) break;
                for (; pos[i] > j; --pos[i])
                {
                    auto sum = nums[pos[i]] + nums[i] + nums[j];
                    if (sum == 0) ret.push_back({nums[i], nums[j], nums[pos[i]]});
                    if (sum <= 0) break;
                }
                pos[i+1] = min(pos[i+1], pos[i]);
            }
        }
        return ret;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.47%)
 * Likes:    366
 * Dislikes: 0
 * Total Accepted:    51.4K
 * Total Submissions: 140K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
#include <vector>
using std::vector;
#include <unordered_map>
#include <set>
#include <algorithm>

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return vector<vector<int>>{};
        std::set<vector<int>> ret;
        std::unordered_map<int, vector<std::pair<int, int>>> cache;

        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i)
        {
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                cache[nums[i] + nums[j]].emplace_back(i, j);
            }
        }

        for (auto &&rp : cache)
        {
            auto found = cache.find(target - rp.first);
            if (found != cache.end())
            {
                for (auto &&low : rp.second)
                {
                    for (auto &&high : found->second)
                    {
                        if (low.second < high.first)
                        {
                            ret.insert(vector<int>{nums[low.first], nums[low.second], nums[high.first], nums[high.second]});

                        }
                    }
                }
            }
        }

        return vector<vector<int>>(ret.cbegin(), ret.cend());
    }
};
// @lc code=end


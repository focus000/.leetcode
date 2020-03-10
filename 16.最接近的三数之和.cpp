/*
 * @Author: liyunfang
 * @Date: 2020-01-19 17:10:59
 * @LastEditTime : 2020-01-24 00:28:23
 * @Description: 
 */
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (42.40%)
 * Likes:    339
 * Dislikes: 0
 * Total Accepted:    66.9K
 * Total Submissions: 157.3K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long ret = INT_MAX;
        for (size_t i = 0; i < nums.size() - 2; ++i)
        {
            size_t l = i + 1;
            size_t r = nums.size() - 1;
            while (l < r)
            {
                auto tmp = nums[i] + nums[l] + nums[r];
                if (tmp > target) --r;
                else if (tmp < target) ++l;
                else return target;
                ret = abs(tmp - target) < abs(ret - target) ? tmp : ret;
            }
        }
        return ret;
    }
};
// @lc code=end


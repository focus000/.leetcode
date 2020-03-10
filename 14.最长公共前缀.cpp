/*
 * @Author: liyunfang
 * @Date: 2020-01-18 00:34:53
 * @LastEditTime : 2020-01-18 01:27:18
 * @Description: 
 */
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.66%)
 * Likes:    839
 * Dislikes: 0
 * Total Accepted:    173.5K
 * Total Submissions: 484.3K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto len = strs.size();
        if (!len) return "";
        if (len == 1) return strs[0];
        size_t pos = 0;
        // if (!strs[len-1].size() || !strs[len-2].size()) return "";
        while (pos != min(strs[len-1].size(), strs[len-2].size()) && strs[len-1][pos] == strs[len-2][pos])
        {
            ++pos;
        }
        strs.pop_back();
        strs.back() = strs.back().substr(0, pos);
        return longestCommonPrefix(strs);
    }
};
// @lc code=end


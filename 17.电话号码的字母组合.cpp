/*
 * @Author: liyunfang
 * @Date: 2020-01-24 00:51:05
 * @LastEditTime : 2020-01-27 00:56:46
 * @Description: 
 */
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (51.82%)
 * Likes:    548
 * Dislikes: 0
 * Total Accepted:    71K
 * Total Submissions: 136.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        // else if (digits.size() == 1) return {nums[digits[0] - '1']};
        else
        {
            vector<string> ret{""};
            for (auto &&num : digits)
            {
                if (num == '1') continue;
                vector<string> tmp;
                for (auto ch : nums[num - '1'])
                {
                    for (auto &&str : ret)
                    {
                        tmp.push_back(str + ch);
                    }
                }
                tmp.swap(ret);
            }
            return ret;
        }
    }
private:
    vector<string> nums{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
// @lc code=end


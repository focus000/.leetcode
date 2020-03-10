/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (72.71%)
 * Likes:    783
 * Dislikes: 0
 * Total Accepted:    81.8K
 * Total Submissions: 111.3K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
#include <vector>
#include <string>
using std::vector, std::string;
// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (!n) return vector<string>{""};
        for (size_t i = 0; i < n; ++i)
        {
            auto tmp = str_mul(str_mul(str_mul(vector<string>{"("}, generateParenthesis(i)), vector<string>{")"}), generateParenthesis(n-1-i));
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }
        return ret;
    }
    vector<string> str_mul(vector<string> lhs, vector<string> rhs)
    {
        vector<string> ret;
        for (auto &&lstr : lhs)
        {
            for (auto &&rstr : rhs)
            {
                ret.push_back(lstr + rstr);
            }
        }
        return ret;
    }
};
// @lc code=end


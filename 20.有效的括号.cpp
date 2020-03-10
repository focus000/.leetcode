/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.36%)
 * Likes:    1421
 * Dislikes: 0
 * Total Accepted:    219.1K
 * Total Submissions: 533.6K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include <string>
using std::string;
#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> tmp;
        for (auto &&c : s)
        {
            if (c == '{' || c == '(' || c == '[')
            {
                tmp.push(c);
            }
            else if (tmp.empty())
            {
                return false;
            }
            else if (c == '}' && tmp.top() == '{' || c == ']' && tmp.top() == '[' || c == ')' && tmp.top() == '(')
            {
                tmp.pop();
            }
            else
            {
                return false;
            }
        }
        if (tmp.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end


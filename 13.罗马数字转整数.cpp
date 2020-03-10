/*
 * @Author: liyunfang
 * @Date: 2020-01-11 07:56:11
 * @LastEditTime : 2020-01-18 00:06:05
 * @Description: 
 */
/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
// #include <map>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> trans{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ret = 0, tmp = 0;
        for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
        {
            if (iter != s.rbegin() && trans[*iter] < tmp)
            {
                ret -= trans[*iter];
            }
            else
            {
                ret += trans[*iter];
            }
            tmp = trans[*iter];
        }
        return ret;
    }
};
// @lc code=end


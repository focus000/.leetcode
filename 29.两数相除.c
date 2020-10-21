/*
 * @lc app=leetcode.cn id=29 lang=c
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (19.01%)
 * Likes:    415
 * Dislikes: 0
 * Total Accepted:    62.1K
 * Total Submissions: 308.5K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
 * -2
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */

// @lc code=start
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
#define FORBID_LIFT_SHIFT 0x40000000

int divide(int dividend, int divisor){
    if (divisor == -1) {
        if (dividend == INT_MIN) {
            return INT_MAX;
        } else {
            return -dividend;
        }
    }
    if (divisor == 1) return dividend;

    int flag = 1;
    if (divisor < 0) {
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) {
                return 1;
            } else {
                return 0;
            }
        }
        divisor = -divisor;
        flag = -flag;
    }
    if (dividend < 0) {
        if (dividend == INT_MIN) {
            return flag * (divide(dividend + divisor, divisor) - 1);
        }
        dividend = -dividend;
        flag = -flag;
    }

    // int dividend_1 = dividend >> 1;
    // int dividend_2 = dividend - dividend_1;
    // int ret_1 = _divide(dividend_1, divisor);
    // int ret_2 = _divide(dividend_2, divisor);
    // return flag * (ret_1 + ret_2);
    return flag * _divide(dividend, divisor);
}

int _divide(int dividend, int divisor) {
    int ret = 0;
    int i = 0;
    while (dividend >= divisor) {
        if (divisor >= FORBID_LIFT_SHIFT) break;
        divisor <<= 1;
        ++i;
    }
    while (i >= 0) {
        if (dividend >= divisor) {
            ret += (1 << i);
            dividend -= divisor;
        }
        --i;
        divisor >>= 1;
    }
    return ret;
}
// @lc code=end


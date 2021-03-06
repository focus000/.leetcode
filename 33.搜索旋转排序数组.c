/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (38.86%)
 * Likes:    980
 * Dislikes: 0
 * Total Accepted:    176.2K
 * Total Submissions: 451K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start
#include <stdlib.h>

int compare(const int *a, const int *b)
{
    return *a - *b;
}

int search(int* nums, int numsSize, int target){
    if (numsSize == 0) return -1;
    if (numsSize == 1) {
        if (target == nums[0]) return 0;
        else return -1;
    }
    int *p;
    int lRet;
    int left = nums[0];
    int right = nums[numsSize - 1];
    if (left < right) {
        if ((left <= target) && (target <= right)) {
            p = bsearch(&target, nums, numsSize, sizeof(int), compare);
            if (!p) {
                return -1;
            } else {
                return p - nums;
            }
        } else {
            return -1;
        }
    } else {
        int mid = numsSize / 2;
        lRet = search(nums, mid, target);
        if (lRet != -1) {
            return lRet;
        } else {
            lRet = search(nums+mid, numsSize - mid, target);
            if (lRet != -1) {
                return mid + lRet;
            } else {
                return -1;
            }
        }
    }
}
// @lc code=end


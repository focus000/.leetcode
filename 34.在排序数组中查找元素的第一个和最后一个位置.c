/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (40.32%)
 * Likes:    602
 * Dislikes: 0
 * Total Accepted:    136.5K
 * Total Submissions: 337.9K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>

inline int leftSearch(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (left != numsSize && nums[left] == target) return left;

    return -1;
}

inline int rightSearch(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (right != -1 && nums[right] == target) {
        return right;
    }

    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ret = (int *)malloc(sizeof(int) * (*returnSize));
    ret[0] = leftSearch(nums, numsSize, target);
    ret[1] = rightSearch(nums, numsSize, target);
    return ret;
}
// @lc code=end


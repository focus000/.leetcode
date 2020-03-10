/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (48.25%)
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    81.1K
 * Total Submissions: 164.6K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };
#include <vector>
using std::vector;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        if (lists.size() == 2) return merge2Lists(lists[0], lists[1]);
        auto mid_iter = lists.begin() + lists.size()/2;
        auto lhs = vector<ListNode*>(lists.begin(), mid_iter);
        auto rhs = vector<ListNode*>(mid_iter, lists.end());
        return merge2Lists(mergeKLists(lhs), mergeKLists(rhs));
    }
    ListNode* merge2Lists(ListNode *lhs, ListNode *rhs)
    {
        if (!lhs) return rhs;
        if (!rhs) return lhs;
        auto head = (lhs->val < rhs->val) ? lhs : rhs;
        auto nonhead = (lhs->val < rhs->val) ? rhs : lhs;
        head->next = merge2Lists(head->next, nonhead);
        return head;
    }
};
// @lc code=end


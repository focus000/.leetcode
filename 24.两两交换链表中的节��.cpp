/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (63.51%)
 * Likes:    427
 * Dislikes: 0
 * Total Accepted:    78.3K
 * Total Submissions: 121.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto fakeHead = new ListNode(0);
        fakeHead->next = head;
        auto curr = fakeHead, prev = head;
        while (prev && prev->next)
        {
            curr->next = prev->next;
            curr = curr->next;
            prev->next = curr->next;
            curr->next = prev;
            curr = curr->next;
            prev = prev->next;
        }
        return fakeHead->next;
    }
};
// @lc code=end


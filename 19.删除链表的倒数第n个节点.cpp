/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (36.90%)
 * Likes:    711
 * Dislikes: 0
 * Total Accepted:    131.3K
 * Total Submissions: 347.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto sentinel = new ListNode(0);
        sentinel->next = head;
        auto expl = head, curr = head, prev = sentinel;
        for (int i = 0; i < n; ++i)
        {
            expl = expl->next;
        }
        while (expl)
        {
            curr = curr->next;
            prev = prev->next;
            expl = expl->next;
        }
        prev->next = curr->next;
        delete curr;
        return sentinel->next;
    }
};
// @lc code=end

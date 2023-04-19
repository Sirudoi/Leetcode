//142. 环形链表 II
//https://leetcode.cn/problems/linked-list-cycle-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//判断链表是否成环，成环返回环入口
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;

        //快慢指针，找第一次相遇
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;

            if (slow == fast) break;
        }

        // cout << fast->val << ' ' << slow->val << endl;
        //链表没环
        if (!fast) return nullptr;

        //有环，慢指针不变，快指针放到链表头，同时走一步，相遇则为环入口
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};
//判断链表是否成环
//https://leetcode.cn/problems/linked-list-cycle/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//定义快慢指针，如果成环，两个指针会指向同一位置
//否则不会指向同一位置
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && slow)
        {
            fast = fast->next;
            slow = slow->next;
            if (slow) slow = slow->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};
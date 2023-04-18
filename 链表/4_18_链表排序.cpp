/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//链表排序
//归并，自顶向下
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head, nullptr);
    }

    ListNode* mergeSort(ListNode* head, ListNode* tail) {
        //节点为空，返回
        if (head == nullptr)
            return head;
        
        //只有一个节点，返回
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* fast = head, *slow = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }

        //左区间排序好后的头节点，右区间排序好后的头结点
        return merge(mergeSort(head, slow), mergeSort(slow, tail));
    }

    //归并后返回新区间的头节点
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* newHead = new ListNode(0);
        ListNode* cur = newHead, *_left = left, *_right = right;

        //归并
        while (_left && _right) {
            ListNode* tmp = new ListNode(0);
            if (_left->val < _right->val) {
                tmp->val = _left->val;
                _left = _left->next;
            } else {
                tmp->val = _right->val;
                _right = _right->next;
            }
            cur->next = tmp;
            cur = cur->next;
        }

        //尾处理
        if (_left == nullptr) {
            cur->next = _right;
        } else {
            cur->next = _left;
        }

        return newHead->next;
    }

};
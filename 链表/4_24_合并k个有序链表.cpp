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
 
//23. 合并 K 个升序链表
//https://leetcode.cn/problems/merge-k-sorted-lists/
//多路归并
class Solution {
private:
    ListNode* _head;
public:
    struct Compare {
        bool operator()(const ListNode* n1, const ListNode* n2) {
            return n1->val > n2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> _pq;
        _head = new ListNode(0);
        ListNode* cur = _head;

        for (auto& node : lists) {
            if (node != nullptr) 
                _pq.push(node);
        }

        while (_pq.size() > 1) {
            cur->next = _pq.top();
            cur = cur->next;
            _pq.pop();

            //堆顶所在链表没遍历完毕，继续插入
            if (cur->next != nullptr)
                _pq.push(cur->next);
        }

        if (_pq.size() >= 1) cur->next = _pq.top();
        return _head->next;
    }
};
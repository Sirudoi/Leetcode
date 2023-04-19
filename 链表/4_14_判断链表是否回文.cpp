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
//Q(n)空间复杂度
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;
        
        vector<int> tmp;
        ListNode* cur = head;
        while (cur)
        {
            tmp.emplace_back(cur->val);
            cur = cur->next;
        }

        int left = 0;
        int right = tmp.size() - 1;
        while (left <= right)
        {
            if (tmp[left] != tmp[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

//O(1)空间复杂度
//快慢指针找中心，然后反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head)
            return false;

        ListNode* fast = head;
        ListNode* slow = head;
        while (slow) {
               fast = fast->next;
               slow = slow->next ? slow->next->next : slow->next;
        }

        ListNode* rightHead = reverseList(fast);
        ListNode* leftHead = head;

        while (leftHead && rightHead) {
            if (leftHead->val != rightHead->val)
                return false;
            leftHead = leftHead->next;
            rightHead = rightHead->next;
        }
        return true;
    }
};
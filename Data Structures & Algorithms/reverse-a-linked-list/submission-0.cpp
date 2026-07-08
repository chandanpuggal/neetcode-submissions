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

    // LeetCode: https://leetcode.com/problems/reverse-linked-list/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=G0_I-ZF0S38

    ListNode *newHead = NULL;

    ListNode* reverseInternal(ListNode* node) {

        if (node->next == NULL) {
            newHead = node;
            return newHead;
        }
        ListNode *newNode = reverseInternal(node->next);
        newNode->next = node;
        node->next = NULL;
        return node;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        
        reverseInternal(head);
        return newHead;
    }
};

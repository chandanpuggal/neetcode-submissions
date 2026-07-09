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
    // LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=XVuQxVej6y8

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* left = NULL;
        ListNode* right = head;

        for (int i = 0; i < n; i++) {
            right = right->next;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        left = dummy;

        while (right != NULL) {
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;

        return dummy->next;
    }
};

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

    // LeetCode: https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=XIdigk956u0

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;
        
        ListNode* temp = list1;

        if (list1->val > list2->val) {
            temp = list2;
            list2 = list1;
            list1 = temp;
        }
        ListNode* head = list1;
        ListNode* l1Next = list1->next;
        ListNode* l2Next;

        while ((l1Next != NULL) && (list2 != NULL)) {
            if (l1Next->val > list2->val) {
                l1Next = list1->next;
                l2Next = list2->next;
                list1->next = list2;
                list2->next = l1Next;
                list2 = l2Next;
                list1 = list1->next;
            } else {
                list1 = list1->next;
                l1Next = l1Next->next;
            }
        }

        if (list2 != NULL) {
            list1->next = list2;
        }

        return head;
    }
};

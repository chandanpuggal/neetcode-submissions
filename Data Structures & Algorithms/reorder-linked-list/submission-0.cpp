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
    // LeetCode: https://leetcode.com/problems/reorder-list/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=S5bfdUTrKLM

    void reorderList(ListNode* head) {

        ListNode* result = NULL;
        ListNode* temp = head;
        ListNode* current;
        ListNode* nxt;
        unordered_map<int, ListNode*> nodesMap;
        int position = 0, currentPosition = 0, size;

        // building nodesMap to store the position of nodes
        while (temp != NULL) {
            nodesMap[position] = temp;
            temp = temp->next;
            position++;
        }
        size = position;
        
        while (currentPosition <= (size - 1)/ 2) {
            current = nodesMap[currentPosition];
            nxt = nodesMap[size - currentPosition - 1];
            nxt->next = NULL;

            if (current != nxt)
                current->next = nxt;
            else
                current->next = NULL;

            if (result == NULL) {
                result = current;
            } else {
                temp->next = current;
            }
            
            temp = nxt;
            currentPosition++;
        }
    }
};

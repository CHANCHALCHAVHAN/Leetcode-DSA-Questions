/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int count = 1 ;
        while(current != nullptr){
            count ++ ;
            current = current -> next;
        }
        count = count - n ;
        if(count == 1){
            head = head->next;
            return head;
        }
        int index = 2;
        ListNode* prev = head;
        current = prev->next;
        while(current != nullptr){
            if(index == count){
                prev -> next = current->next;
                current->next = nullptr;
            }
            prev = prev->next;
            current = current->next;
            index++;

        }
        return head;

    }
};

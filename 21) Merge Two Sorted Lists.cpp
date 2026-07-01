/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sorted = new ListNode(0);
        ListNode* current = sorted ;
        

        while(list1 != nullptr || list2 != nullptr){
            int val1 =-101 , val2 = -101;
            if(list1 != nullptr ){
                val1 = list1->val ;
            }

            if(list2 != nullptr){
                val2 = list2->val;
            }

            if(val1 != -101 && val2 != -101){
                if(val1 <= val2){
                    ListNode* newnode = new ListNode(val1);
                    current->next = newnode;
                    current = newnode ;
                    list1 = list1->next;
                }
                else if(val1 > val2 ){
                    ListNode* newnode = new ListNode(val2);
                    current->next = newnode;
                    current = newnode ;
                    list2= list2->next ;
                }
            }
            else if(val1 == -101 && val2 != -101){
                ListNode* newnode = new ListNode(val2);
                current->next = newnode;
                current = newnode ;
                list2= list2->next ;
            }
            else if (val1 != -101 && val2 == -101){
                ListNode* newnode = new ListNode(val1);
                current->next = newnode;
                current = newnode ;
                list1 = list1->next;
            }
        }
        return sorted->next;
    }
};

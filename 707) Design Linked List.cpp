/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
*/

class MyLinkedList {
public:
    struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;

    // Constructor
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};
    ListNode* head ;
    ListNode* tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    
    int get(int index) {
        ListNode* current = head;
        int n = 0 ;

        if (index < 0 || index >= size) return -1;

        while( current != nullptr){
            if(n == index){
                std::cout<<"accesssed";
                return current->val;
            }
            n++;
            current = current->next;;
        }
        return -1 ;   
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
        size ++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(head == nullptr){
            head = newNode ;
            tail = newNode ;
        }
        else{
            newNode -> prev = tail;
            tail-> next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* newNode = new ListNode(val);
        int i = 0;
        ListNode* current = head;

        if(index < 0 || index > size) return ;
        if(index == 0) {
                addAtHead(val);
                return;
            }
            if(index == size){
                addAtTail(val);
                return;
            }
        
        while(current != nullptr){
            if( i == index){
                current->prev->next = newNode;
                newNode->prev = current->prev;
                newNode-> next = current;
                current->prev = newNode;
                size++;
                break;
            }
            i++;
            current = current->next;
        }
        std::cout<<"inserted succssfully";
        

    }
    
    void deleteAtIndex(int index) {
        int i = 0;
        ListNode* current = head;
        if(index < 0 || index >= size) return ;

        while(current != nullptr){
            if(index == 0 && size == 1) {
                tail = nullptr;
                head = nullptr;
                delete current;
                break;
                }
            if( i == index){
                if(tail == current ){
                    tail = current->prev;
                    current->prev->next = nullptr;
                    current->prev = nullptr;
                    delete current;
                    break;
                }
                else if( current == head){
                    head = current->next;
                    current->next->prev = nullptr;
                    current->next = nullptr;
                    delete current;
                    break;
                }
                else{
                    current->prev->next = current-> next;
                    current->next->prev = current->prev;
                    delete current ;
                    break;
                }
            }
            i++;
            current = current->next;
        }
        
        size--;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

#include<bits/stdc++.h>
using namespace std;

/* Question 29 */
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
    LLNode* reverseLinkedList(LLNode*);
    LLNode* addLinkedList(LLNode*, LLNode*);
};

LLNode* LLNode::reverseLinkedList(LLNode* head) {
    LLNode *prev = nullptr;
    LLNode *cur = head;
    LLNode *next = nullptr;

    while (cur != nullptr) {
        next = cur->next; 
        cur->next = prev; 
        prev = cur;       
        cur = next;       
    }

    return prev;
}


/* Question 30 */
LLNode* LLNode::addLinkedList(LLNode* l0, LLNode* l1) {
    LLNode dummy(0, nullptr);
    LLNode* tail = &dummy;
    
    // carry of the sum
    int carry = 0;
    
    // Traverse both lists
    while (l0 != nullptr || l1 != nullptr || carry != 0) {
        int sum = carry;
        
        // calculate the sum of corresponding elements of both array
        if (l0 != nullptr) {
            sum += l0->val;
            l0 = l0->next;
        }
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        // calculate the carry
        carry = sum / 10;
        tail->next = new LLNode(sum % 10, nullptr);
        tail = tail->next;
    }
    
    return dummy.next;
}


class LinkedList {
public: 
    class Node;
private:
    Node* head;
    Node* tail;
    int size;
public: 
    class Node {
        private: 
            int value;
            Node* next;
            friend class LinkedList;
        public:
            Node() {
                this->next = NULL;
            }
            Node(Node* node) {
                this->value = node->value;
                this->next = node->next;
            }
            Node(int value, Node* next = NULL) {
                this->value = value;
                this->next = next;
            }
    };
    LinkedList(): head(NULL), tail(NULL), size(0) {};
    void partition(int k);
};

/* Question 31 */
void LinkedList::partition(int k) {
    if (this->head == nullptr || this->head->next == nullptr) {
        return; // Danh sách rỗng hoặc chỉ có 1 phần tử
    }

    // Các con trỏ đầu và đuôi cho 3 nhóm
    Node *sHead = nullptr, *sTail = nullptr; 
    Node *eHead = nullptr, *eTail = nullptr;
    Node *gHead = nullptr, *gTail = nullptr;

    Node* cur = this->head;

    // Phân loại từng phần tử vào 3 nhóm
    while (cur != nullptr) {
        Node* nextNode = cur->next; // Lưu phần tử tiếp theo
        cur->next = nullptr;       // Cắt liên kết cũ để tránh vòng lặp

        if (cur->value < k) {
            if (sHead == nullptr) {
                sHead = sTail = cur;
            } else {
                sTail->next = cur;
                sTail = cur;
            }
        } else if (cur->value == k) {
            if (eHead == nullptr) {
                eHead = eTail = cur;
            } else {
                eTail->next = cur;
                eTail = cur;
            }
        } else { // cur->value > k
            if (gHead == nullptr) {
                gHead = gTail = cur;
            } else {
                gTail->next = cur;
                gTail = cur;
            }
        }

        cur = nextNode;
    }

    // Tiến hành nối 3 nhóm lại với nhau: Smaller -> Equal -> Greater
    Node* newHead = nullptr;
    Node* newTail = nullptr;

    // 1. Nhóm Smaller
    if (sHead != nullptr) {
        newHead = sHead;
        newTail = sTail;
    }

    // 2. Nhóm Equal
    if (eHead != nullptr) {
        if (newHead == nullptr) {
            newHead = eHead;
        } else {
            newTail->next = eHead;
        }
        newTail = eTail;
    }

    // 3. Nhóm Greater
    if (gHead != nullptr) {
        if (newHead == nullptr) {
            newHead = gHead;
        } else {
            newTail->next = gHead;
        }
        newTail = gTail;
    }

    // Cập nhật lại head và tail của danh sách chính
    this->head = newHead;
    this->tail = newTail;
}


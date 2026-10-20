/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Create clone nodes and insert them next to original nodes
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            Node* clone = new Node(curr->val);
            curr->next = clone;
            clone->next = nextNode;
            curr = nextNode;
        }
        
        // Step 2: Assign random pointers for the cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate the original and cloned lists
        curr = head;
        Node* cloneHead = head->next;
        while (curr) {
            Node* clone = curr->next;
            curr->next = clone->next;
            curr = curr->next;
            if (clone->next) {
                clone->next = clone->next->next;
            }
        }
        
        return cloneHead;
    }
};
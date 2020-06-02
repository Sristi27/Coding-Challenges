Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
  
//c++ solution
  
class Solution {
public:
    void deleteNode(ListNode* node) {
        
       ListNode*temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        //e(temp);
    }
};
  

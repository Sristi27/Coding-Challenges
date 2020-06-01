Question: Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.

//C++ soln

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
     ListNode* h1=head;
        int count=0;
        while(h1!=NULL)
        {
            count++;
            h1=h1->next;
        }
        if (count%2==0)
        {
            count=count/2;
            count+=1;
    }
        else
            count=(count+1)/2;
        int i=1;
        while(i!=count)
        {
            head=head->next;
            i+=1;
        }
        return head;
    }
};

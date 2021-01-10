Remove Duplicates from Sorted List II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
C++	






1
/**
2
 * Definition for singly-linked list.
3
 * struct ListNode {
4
 *     int val;
5
 *     ListNode *next;
6
 *     ListNode() : val(0), next(nullptr) {}
7
 *     ListNode(int x) : val(x), next(nullptr) {}
8
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9
 * };
10
 */
 
 
11
class Solution {
12
public:
13
    ListNode* deleteDuplicates(ListNode* A) {
14
        
15
      ListNode *temp=A;
16
      ListNode *prev=NULL;
17
      int val=INT_MAX;
18
      while(temp!=NULL){
19
          
20
        if(temp->next!=NULL && temp->next->val==temp->val){
21
            val=temp->val;
22
            ListNode* x=temp->next;
23
            temp->next=x->next;
24
            // free(x);
25
        }
26
        else{
27
        if(val!=INT_MAX  && temp->val==val){
28
            if(prev==NULL){
29
                ListNode *y=temp;
30
                A=temp->next;
31
                temp=temp->next;
32
                // free(y);
33
            }
34
            else{
35
                ListNode *y=temp;
36
                prev->next=temp->next;
37
                temp=temp->next;
38
                // free(y);
39
            }
40
        }
41
        else{
42
        prev=temp;
43
        temp=temp->next;
44
        }
45
      }
46
    }
47
    return A;
48
    }
 
49
};

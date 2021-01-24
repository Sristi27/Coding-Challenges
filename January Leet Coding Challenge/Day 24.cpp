Merge k Sorted Lists.
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.




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
    struct compare{
14
        bool operator()(ListNode*a,ListNode*b)
15
        {
16
            return a->val>b->val;
17
        }
18
    };
19
    ListNode* mergeKLists(vector<ListNode*>& lists) {
20
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
21
        int n=lists.size();
22
        ListNode*head=new ListNode();
23
        if(n==0) return NULL;
24
        if (n==0 || n==1) return lists[0];
25
        for(int i=0;i<n;i++)
26
        {
27
            if(lists[i])
28
            pq.push(lists[i]);
29
        }
30
        ListNode*dummy=head;
31
        while(!pq.empty())
32
        {
33
            ListNode*temp=pq.top();
34
            pq.pop();
35
            if(temp->next!=NULL)
36
            pq.push(temp->next);
37
            dummy->next=temp;
38
            dummy=dummy->next;
39
        }
40
        return head->next;
41
    }
42
};

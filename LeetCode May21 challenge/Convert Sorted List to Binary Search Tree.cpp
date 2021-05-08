Convert Sorted List to Binary Search Tree

Solution
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 

Example 1:

<img src="https://github.com/Sristi27/Coding-Challenges/blob/master/LeetCode%20May21%20challenge/Screenshot%202021-05-08%20at%2012.25.29%20PM.png">


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [0]
Output: [0]
Example 4:

Input: head = [1,3]
Output: [3,1]
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-10^5 <= Node.val <= 10^5
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
/**
12
 * Definition for a binary tree node.
13
 * struct TreeNode {
14
 *     int val;
15
 *     TreeNode *left;
16
 *     TreeNode *right;
17
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
18
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
19
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
20
 * };
21
 */
22
class Solution {
23
public:
24
    
25
    int countNode(ListNode* temp)
26
    {
27
        int c=0;
28
        while(temp)
29
        {
30
            c++; temp=temp->next;
31
        }
32
        return c;
33
    }
34
    
35
    TreeNode* listToBst(ListNode*head,int start,int end)
36
    {
37
        if(start>end) return NULL;
38
        int mid=start+(end-start)/2;
39
        ListNode* temp=head;
40
        int i=0;
41
        while(temp!=NULL && i<mid)
42
        {
43
            temp=temp->next;
44
            i++;
45
        }
46
        TreeNode* root=new TreeNode(temp->val);
47
        root->left=listToBst(head,start,mid-1);
48
        root->right=listToBst(head,mid+1,end);
49
        return root;
50
    }
51
    
52
    
53
    TreeNode* sortedListToBST(ListNode* head) {
54
        
55
        int len=countNode(head);
56
        return listToBst(head,0,len-1);
57
    }
58
};

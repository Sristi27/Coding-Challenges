Question: ##INVERT A BINARY TREE
//CPP solution

class Solution {
public:
    TreeNode* invertTree(TreeNode* node) {
        
        if (node == NULL) 
		return NULL; 
	else
	{ 
		TreeNode* temp; 
		invertTree(node->left); 
		invertTree(node->right); 
		temp= node->left; 
		node->left = node->right; 
		node->right = temp; 
	} 
        
        return node;
        
    }
};

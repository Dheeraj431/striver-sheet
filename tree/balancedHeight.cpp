//Problem Link : https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node *node){
    if(node == NULL)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}

bool isBalanced(Node *node){
    if(node == NULL)
        return true;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    int heightDiff = abs(leftHeight - rightHeight);

    if(heightDiff <= 1 && isBalanced(node->left) && isBalanced(node->right))
        return true;
    else
        return false;
}

};

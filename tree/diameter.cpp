Problem Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* node, int &dia){
        if(node==NULL){
            return 0;
        }
        int lh=height(node->left,dia);
        int rh=height(node->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
    }
    int diameter(Node* root) {
        if(root==NULL)
          return 0;
        int dia = 0;
        height(root, dia);
        return ++dia;
    }
};

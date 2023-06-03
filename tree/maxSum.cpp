//Problem Link:https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

// User Fuction template for C++

int nullVal = -(int)1e5;
class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int maxPathSumUtil(Node* node, int& maxSum) {
        if (node == NULL)
            return 0;
        
        // Calculate the maximum path sum in the left and right subtrees
        int leftSum = maxPathSumUtil(node->left, maxSum);
        int rightSum = maxPathSumUtil(node->right, maxSum);
        
        // Calculate the maximum sum including the current node
        int nodeSum = max(node->data, max(node->data + leftSum, node->data + rightSum));
        
        // Update the global maximum sum if necessary
        maxSum = max(maxSum, max(nodeSum, node->data + leftSum + rightSum));
        
        // Return the maximum sum including the current node
        return nodeSum;
    }
    
    int findMaxSum(Node* root) {
        int maxSum = INT_MIN; // Initialize the maximum sum to a very small value
        maxPathSumUtil(root, maxSum);
        return maxSum;
    }
};

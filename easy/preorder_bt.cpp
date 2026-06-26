
#include <iostream>
#include<vector>
using namespace std;

// TreeNode structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    // Constructor to initialize
    // the TreeNode with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    private:
    // Function to perform pre order traversal
    // of the tree and store values in 'arr'
    void recursivePreOrder(TreeNode* root, vector<int> &arr){
        // If the current Tree is NULL
        // (base case for recursion), return
        if(root == nullptr){
            return;
        }

         // Push the current TreeNode's
        // value into the vector
        arr.push_back(root->data);

        // Recursively traverse the left subtree
        recursivePreOrder(root->left, arr);
       
        // Recursively traverse 
        // the right subtree
        recursivePreOrder(root->right, arr);
    }
    
    public:
    // Function to initiate inorder traversal
    // and return the resulting vector
    vector<int> preorder(TreeNode* root){
        // Create an empty vector to
        // store inorder traversal values
        vector<int> arr;
        // Call the inorder traversal function
        recursivePreOrder(root, arr);
        // Return the resulting vector
        // containing inorder traversal values
        return arr;
    }
};

// Main function
int main()
{
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol = Solution();
    // Getting inorder traversal
    vector<int> result = sol.preorder(root);

    // Displaying the inorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

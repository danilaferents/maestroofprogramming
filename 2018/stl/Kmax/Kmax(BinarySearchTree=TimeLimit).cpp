/*#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	set<int> array;
	string input;
	int help=0,n=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>input>>help;
		if ((input == "+1") || (input == "1"))
		{
			array.insert(help);
			continue;
		}
		if (input == "-1")
		{
			array.erase(help);
			continue;
		}
		if (input == "0")
		{
			auto it=array.end();
			for (int j = 0; j < help; ++j)
			{
				it--;
			}
			cout<<*it<<endl;
			continue;
		}
	}
}*/
// C++ program to find k'th largest element in BST 
#include<iostream> 
using namespace std; 
  
struct Node 
{ 
    int key; 
    Node *left, *right; 
}; 
  
// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
    Node *temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// A function to find k'th largest element in a given tree. 
void kthLargestUtil(Node *root, int k, int &c) 
{ 
    // Base cases, the second condition is important to 
    // avoid unnecessary recursive calls 
    if (root == NULL || c >= k) 
        return; 
  
    // Follow reverse inorder traversal so that the 
    // largest element is visited first 
    kthLargestUtil(root->right, k, c); 
  
    // Increment count of visited nodes 
    c++; 
  
    // If c becomes k now, then this is the k'th largest  
    if (c == k) 
    { 
        cout<< root->key << endl; 
        return; 
    } 
  
    // Recur for left subtree 
    kthLargestUtil(root->left, k, c); 
} 
  
// Function to find k'th largest element 
void kthLargest(Node *root, int k) 
{ 
    // Initialize count of nodes visited as 0 
    int c = 0; 
  
    // Note that c is passed by reference 
    kthLargestUtil(root, k, c); 
} 
  
/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
struct Node * minValueNode(struct Node* node) 
{ 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
struct Node* deleteNode(struct Node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct Node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct Node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
	Node *root = NULL; 
	string input;
	int help=0,n=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>input>>help;
		if ((input == "+1") || (input == "1"))
		{
			if (root == NULL) 
			{
				root = insert(root,help);
				continue;
			}
			insert(root,help);
			continue;
		}
		if (input == "-1")
		{
			deleteNode(root,help);
			continue;
		}
		if (input == "0")
		{
			kthLargest(root, help);
			continue;
		}
	}
}
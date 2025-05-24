#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> &preorder)
{
    idx++;
    // Check if the root is NULL
    if (preorder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[idx]);

    // if (root->data == -1)
    // {
    //     return root;
    // }

    // Make Left SubTree
    root->left = buildTree(preorder);

    // Make Right SubTree
    root->right = buildTree(preorder);

    return root;
}

// ? Pre-Order Traversal
void preOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Traverse Left Subtree
    cout << root->data << " ";
    preOrderTraverse(root->left);

    // Traverse Right Subtree
    preOrderTraverse(root->right);
    return;
}

// In Order Traverse
void inOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Left Traverse
    inOrderTraverse(root->left);

    // Root Traverse
    cout << root->data << " ";

    // Right Traverse
    inOrderTraverse(root->right);
}

// Post Order Traverse
void postOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Left Traverse
    postOrderTraverse(root->left);

    // Right Traverse
    postOrderTraverse(root->right);

    // Root Traverse
    cout << root->data << " ";
    return;
}

// Level Order Traverse - Iterative
void levelOrderTraverse(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);
    while (Q.size() > 0)
    {
        Node *curr = Q.front();
        Q.pop();
        cout << curr->data << " ";

        if (curr->left != NULL)
        {
            Q.push(curr->left);
        }

        if (curr->right != NULL)
        {
            Q.push(curr->right);
            if (Q.front() == NULL)
            {
                Q.push(NULL);
            }
        }
        if (Q.front() == NULL)
        {
            Q.pop();
            cout << endl;
        }
    }
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    // vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, 8, -1, -1, 9, -1, -1};

    Node *root = buildTree(preorder);
    cout << "PreOrder Traverse" << endl;
    preOrderTraverse(root);

    cout << "\n\nInOrder Traverse" << endl;
    inOrderTraverse(root);

    cout << "\n\nPostOrder Traverse" << endl;
    postOrderTraverse(root);
    cout << endl;

    cout << "\n\nLevelOrder Traverse" << endl;
    levelOrderTraverse(root);
    cout << endl;

    return 0;
}

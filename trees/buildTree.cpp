#include <iostream>
#include <vector>
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
    Node *root = new Node(preorder[idx]);

    // Check if the root is NULL
    if (root->data == -1)
    {
        return root;
    }

    // Make Left SubTree
    root->left = buildTree(preorder);

    // Make Right SubTree
    root->right = buildTree(preorder);

    return root;
}

void traverseTree(Node *root)
{
    if (root->data == -1)
    {
        cout << "-> " << root->data << endl;
        return;
    }

    // Traverse Left Subtree
    cout << "-> " << root->data << endl;
    traverseTree(root->left);

    // Traverse Right Subtree
    traverseTree(root->right);
    return;
}

int main()
{
    vector<int> preorder = {
        1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *tree = buildTree(preorder);
    traverseTree(tree);

    return 0;
}

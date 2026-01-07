#include <iostream>
using namespace std;

class TreeNode
{

public:
    int data;
    TreeNode *left, *right;

    TreeNode()
    {
        left = right = NULL;
        data = 0;
    }
};

class BST
{
public:
    TreeNode *root;
    TreeNode *previous, *current;

    BST()
    {
        root = previous = current = NULL;
    }

    void insert(int d)
    {

        TreeNode *nn = new TreeNode;
        nn->data = d;

        if (root == NULL)
        {
            root = nn;
            cout << "The data has been inserted successfully" << endl;
            return;
        }

        current = root;
        previous = NULL;

        while (current != NULL)
        {
            previous = current;
            if (d < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (nn->data < previous->data)
            previous->left = nn;
        else
            previous->right = nn;

        cout << "The data has been inserted successfully" << endl;
    }

    void searchByData(int d)
    {
        if (root == NULL)
        {
            cout << "The tree is empty" << endl;
            return;
        }

        current = root;

        while (current != NULL)
        {
            if (current->data == d)
                break;
            if (d < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (current == NULL)
        {
            cout << "Node not found" << endl;
            return;
        }

        cout << "Node found" << endl;
    }

    void preOrder(TreeNode *node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
        else
            return;
    }

    void inOrder(TreeNode *node)
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
        else
            return;
    }

    void postOrder(TreeNode *node)
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
        else
            return;
    }

    void displayTree()
    {
        if (root == NULL)
        {
            cout << "The tree is empty" << endl;
            return;
        }

        cout << "Preorder form" << endl;
        preOrder(root);

        cout << "Inorder form" << endl;
        inOrder(root);

        cout << "Postorder form" << endl;
        postOrder(root);
    }

    void deleteNode(int d)
    {

        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        previous = NULL;
        current = root;

        while (current != NULL)
        {
            if (current->data == d)
                break;

            previous = current;

            if (d < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (current == NULL)
        {
            cout << "Block not found" << endl;
            return;
        }

        // case - 1

        if (current->left == NULL && current->right == NULL) // check leaf node condition
        {
            if (current == root)
            {
                root = NULL;
            }
            else
            {

                if (previous->left == current)
                    previous->left = NULL;
                else
                    previous->right = NULL;
            }
            delete current;
            current = NULL;
            cout << "Node has been deleted successfully" << endl;
            return;
        }

        // case 2

        if (current->left == NULL || current->right == NULL) // node with one child
        {

            if (current == root)
            {
                if (root->left != NULL)
                    root = root->left;
                else
                    root = root->right;
            }
            else
            {

                TreeNode *child = NULL;

                if (current->left != NULL)
                    child = current->left;
                else
                    child = current->right;

                if (previous->left == current)
                    previous->left = child;
                else
                    previous->right = child;
            }

            delete current;
            current = NULL;
            cout << "The node has been deleted successfully" << endl;
            return;
        }

        // case 3
        // node with two child

        TreeNode *parentSucc = current;
        TreeNode *succ = current->right;

        while (succ->left != NULL)
        {
            parentSucc = succ;
            succ = succ->left;
        }

        current->data = succ->data;

        if (parentSucc->left == succ)
            parentSucc->left = succ->right;
        else
            parentSucc->right = succ->right;

        delete succ;
        succ = NULL;

        cout << "Node has been deleted successfully" << endl;
    }
};

int main()
{

    return 0;
}
#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void allTraversals(Node* root,
                   list<int>& preorder,
                   list<int>& inorder,
                   list<int>& postorder) {

    if (root == nullptr)
        return;

    // Pair contains: {node, state}
    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {

        Node* current = st.top().first;
        int state = st.top().second;

        // State 1: Preorder (Root)
        if (state == 1) {
            preorder.push_back(current->data);

            // Change current node's state from 1 to 2
            st.top().second = 2;

            // Process left child
            if (current->left != nullptr) {
                st.push({current->left, 1});
            }
        }

        // State 2: Inorder (Root)
        else if (state == 2) {
            inorder.push_back(current->data);

            // Change current node's state from 2 to 3
            st.top().second = 3;

            // Process right child
            if (current->right != nullptr) {
                st.push({current->right, 1});
            }
        }

        // State 3: Postorder (Root)
        else {
            postorder.push_back(current->data);
            st.pop();
        }
    }
}

void printList(const list<int>& traversal) {
    for (int value : traversal) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    /*
              1
             / \
            2   3
           / \
          4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    list<int> preorder;
    list<int> inorder;
    list<int> postorder;

    allTraversals(root, preorder, inorder, postorder);

    cout << "Preorder: ";
    printList(preorder);

    cout << "Inorder: ";
    printList(inorder);

    cout << "Postorder: ";
    printList(postorder);

    return 0;
}
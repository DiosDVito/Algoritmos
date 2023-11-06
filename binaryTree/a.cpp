#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}


int height(Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool ancestors(Node* root, int target, vector<int>& path) {
    if (root == NULL) {
        return false;
    }
    path.push_back(root->data);
    if (root->data == target) {
        return true;
    }
    if (ancestors(root->left, target, path) || ancestors(root->right, target, path)) {
        return true;
    }
    path.pop_back();
    return false;
}

int whatlevelamI(Node* root, int target) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == target) {
        return 0;
    }
    int leftLevel = whatlevelamI(root->left, target);
    if (leftLevel != -1) {
        return leftLevel + 1;
    }
    int rightLevel = whatlevelamI(root->right, target);
    if (rightLevel != -1) {
        return rightLevel + 1;
    }
    return -1;
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == nullptr)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
                
};

void preOrder(Node* root){
    if(root == nullptr)
        return;
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
   
};

void visit(Node* root, int n) {
    if (n == 1)
    preOrder(root);

    else if (n == 2)
    inOrder(root);

    else if (n == 3)
    postOrder(root);

    else{
        cout << "invalid" << endl;
    }
}

int main() {
    Node* root = createNode(5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 1);
    insertNode(root, 10);
    insertNode(root, 4);
    insertNode(root, 6);

    int n;
    cin >> n;
    visit(root, n);

    cout << "Height of tree: " << height(root) << endl;

    int target;
    cout << "Enter the number which ancestor(s) you want to find: " << endl;
    cin >> target;

    vector<int> path;
    if (ancestors(root, target, path)) {
        cout << "Ancestors of " << target << ": ";
        for (int i = 0; i < path.size() - 1; i++) {
            cout << path[i] << " -> ";
        }
        cout << path[path.size() - 1] << endl;
    } else {
        cout << target << " is not in the tree." << endl;
    }

    cout << "Enter number which level you want to find: " << endl;
    cin >> target;

    int level = whatlevelamI(root, target);
    if (level != -1) {
        cout << target << " is at level " << level << endl;
    } else {
        cout << target << " is not in the tree." << endl;
    }

    return 0;

}
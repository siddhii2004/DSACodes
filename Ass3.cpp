#include<iostream>
using namespace std;

class node 
{
public:
    int data;
    node* left;
    node* right;
    
    node() {
        left = NULL;
        right = NULL;
    }
};

class BST 
{
public:
    node* root;
    
    BST() {
        root = NULL;
    }
    
    ~BST() {
        destroyTree(root);
    }
    
    void destroyTree(node* r) {
        if (r != NULL) {
            destroyTree(r->left);
            destroyTree(r->right);
            delete r;
        }
    }
    
    void insert(int data);
    void inorder(node* temp);
    void smallest();
    void largest();
    bool search(node* temp, int key);
    void Mirror(node* r);
    int height(node* r);      
};

int BST::height(node* r) {
    if (r == NULL)
        return 0;
    
    int Left_Height = height(r->left);
    int Right_Height = height(r->right);
    
    return max(Left_Height, Right_Height) + 1;
}

void BST::Mirror(node* r) {
    if (r != NULL) {
        node* temp = r->left;
        r->left = r->right;
        r->right = temp;
        
        Mirror(r->left);
        Mirror(r->right);
    }
}

bool BST::search(node* temp, int key) {
    if (temp == NULL)
        return false;
    
    if (temp->data == key)
        return true;
    
    if (key < temp->data)
        return search(temp->left, key);
    else
        return search(temp->right, key);
}

void BST::smallest() {
    node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    
    cout << "\nSmallest node in the tree is: " << temp->data;    
}

void BST::largest() {
    node* temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    
    cout << "\nLargest node in the tree is: " << temp->data;
}

void BST::insert(int data) {
    node* new_node = new node();
    new_node->data = data;
    
    if (root == NULL) {
        root = new_node;
        return;
    }
    
    node* temp = root;
    while (true) {
        if (data < temp->data) {
            if (temp->left == NULL) {
                temp->left = new_node;
                return;
            }
            temp = temp->left;
        } else if (data > temp->data) {
            if (temp->right == NULL) {
                temp->right = new_node;
                return;
            }
            temp = temp->right;
        } else {
            cout << "\nData is already exist in the tree";
            return;
        }
    }
}

void BST::inorder(node* temp) {
    if (temp != NULL) {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }
}

int main() {
    int ch;
    BST B;
    
    do {
        cout << "\n Menu";
        cout << "\n1. Insert";
        cout << "\n2. Inorder";
        cout << "\n3. Smallest number";
        cout << "\n4. Largest number";  
        cout << "\n5. Search";  
        cout << "\n6. Mirror";
        cout << "\n7. Height of the tree";
        cout << "\n8. Exit";
        cout << "\nEnter your choice : ";
        cin >> ch;
        
        switch(ch) {
            case 1: {
                int data;
                cout << "Enter data: ";
                cin >> data;
                B.insert(data);
                break;
            }
            case 2:
                cout << "\nInorder traversal: ";
                B.inorder(B.root);
                break;
            case 3:
                B.smallest();
                break;
            case 4:
                B.largest();
                break;
            case 5: {
                int key;
                cout << "Enter number to search: ";
                cin >> key;
                if (B.search(B.root, key))
                    cout << "Number is found";
                else
                    cout << "Number is not found";
                break;
            }
            case 6:
                B.Mirror(B.root);
                cout << "\nMirror image of the tree is obtained.";
                break;
            case 7:
                cout << "\nHeight of the BST is: " << B.height(B.root);
                break;
            case 8:
                cout << "\nExiting...";
                break;
            default:
                cout << "\nEnter correct choice ";
                break;
        }
    } while (ch != 8);
    
    return 0;
}


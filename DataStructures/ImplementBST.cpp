#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST{
    
private:
    Node* root;

    Node* InsertDataIntoTreeUtil(Node* root, int data){
        if(!root){
            return new Node(data);
        }
        if(data < root->data) root->left = InsertDataIntoTreeUtil(root->left, data);
        else root->right = InsertDataIntoTreeUtil(root->right, data);
        return root;
    }

public:
    BST(){
        root = NULL;
    }
    Node* getRoot(){
        return this->root;
    }

    void InsertDataIntoTree(int data){
        this->root = InsertDataIntoTreeUtil(this->root, data);
    }

    void PreorderTraversal(Node* root){
        if(!root)return;

        cout<<root->data<<" ";

        PreorderTraversal(root->left);
        PreorderTraversal(root->right);

        return;
    }

    void InorderTraversal(Node* root){
        if(!root)return;

        InorderTraversal(root->left);
        cout<<root->data<<" ";
        InorderTraversal(root->right);

        return;

    }

    void PostorderTraversal(Node* root){
        if(!root)return;

        PostorderTraversal(root->left);
        PostorderTraversal(root->right);

        cout<<root->data<<" ";

        return;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    BST bst;
    bst.InsertDataIntoTree(50);
    bst.InsertDataIntoTree(30);
    bst.InsertDataIntoTree(20);
    bst.InsertDataIntoTree(40);
    bst.InsertDataIntoTree(70); 
    Node* root = bst.getRoot();
    bst.InorderTraversal(root);
    return 0;
}


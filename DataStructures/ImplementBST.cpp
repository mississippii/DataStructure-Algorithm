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

void InsertDataIntoTree(Node *root,int data){

    if(root->data > data){
        if(root->left)InsertDataIntoTree(root->left,data);
        else root->left = new Node(data);
    }
    else{
        if(root->right) InsertDataIntoTree(root->right, data);
        else root->right = new Node(data);
    }

    return;
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
int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        Node* Root=NULL;
        cout<<"How many data you want to Insert into Tree : ";
        int n;
        cin>>n;
        while(n--){
            int data;
            cin>>data;
            if(!Root)Root = new Node(data);
            else InsertDataIntoTree(Root,data);
        }
        cout<<"Travers Into Tree :\nPreOrder Traversal : ";
        PreorderTraversal(Root);
        cout<<endl<<"Inorder Traversal : ";
        InorderTraversal(Root);
        cout<<endl<<"Postorder Traversal : ";
        PostorderTraversal(Root);
        cout<<endl;

    }
    return 0;
}


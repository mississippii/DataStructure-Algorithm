#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int val, Node* previous){
        data = val;
        prev = previous;
        next = NULL;
    }
};

void InsertIntoLinkedList(Node* head , int data){
    while(head->next)
            head = head->next;
    head->next= new Node(data,head);
    return;
}

void Display(Node *head){
    while(head){
    if(head->prev==NULL)cout<<"NULL ";
    else cout<<head->prev->data<<" ";
    cout<<head->data<<" ";
    if(head->next==NULL)cout<<"NULL ";
    else  cout<<head->next->data<<"";
    head = head->next;
    cout<<endl;
    }
}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        Node * head= NULL;
        int n;
        cin>>n;
        while(n--){
            int x;
            cin>>x;
            if(head == NULL)head = new Node(x,NULL);
            else InsertIntoLinkedList(head,x);
        }
        Display(head);
    }
    return 0;
}
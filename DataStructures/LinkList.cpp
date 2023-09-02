#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN


struct Node{
    int data;
    Node *next;

    Node(int x){
       data=x;
       next=NULL;
    }
};

void InsertIntoLonkList(Node * head,int data){
    while(head->next!=NULL)head=head->next;
    head->next= new Node(data);
}

void Display(Node *head){
    while(head!=NULL){
        cout<<head->data<<"---> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
    return;
}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
       Node *head=NULL;
       cout<<"PLease enter a number that maximum number you want to store on LinkList : ";
       int n;
       cin>>n;
       while(n--){
        int val;
        cin>>val;
        if(head==NULL)
            head = new Node(val);
        else
            InsertIntoLonkList(head,val);
       }
       Display(head);

    }
    return 0;
}

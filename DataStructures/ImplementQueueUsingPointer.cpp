#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

struct Queue{
    Queue *next;
    int data;
    Queue(int val){
        data = val;
        next=NULL;
    }
};


void InsertIntoQueue(Queue * head ,int data){
    while(head->next)head=head->next;
    Queue *curr = new Queue(data);
    head->next=curr;
}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        Queue *head=NULL;
        cout<<"How many data want to insert into Queue :";
        int x;
        cin>>x;
        while(x--){
            int data;
            cin>>data;
            if(head==NULL)head = new Queue(data);
            else InsertIntoQueue(head,data);
        }
        cout<<"How many value you want to pop :";
        int a;
        cin>>a;

        while(a--){
            if(head==NULL)cout<<"Queue is already Empty !"<<endl;
            else {
                cout<<"Font of Queue is : "<<head->data<<endl;
                Queue *temp=head;
                head=head->next;
                delete temp;
            }

        }
    }
    return 0;
}


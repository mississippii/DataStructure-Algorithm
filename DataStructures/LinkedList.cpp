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


class LinkedList
{
private:
    Node* head;
    Node* taile;
public:
    LinkedList(){
        head=NULL;
        taile=NULL;
    }
    Node* getHead(){
        return head;
    }
    Node* getTail(){
        return taile;
    }
    void insertAtLinkList(int data){
        Node* newNode=new Node(data);
        if(!head){
            head=newNode;
            taile=newNode;
        }
        else{
            taile->next = newNode;
            taile = newNode;
        }
    }
    void createCycleAt(int pos){
        Node* temp=head;
        int count=1;
        while(count<pos){
            temp=temp->next;
            count++;
        }
        taile->next=temp;
    }
    Node* detectCycle(){
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL; // No cycle
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    LinkedList linkedList;
    linkedList.insertAtLinkList(10);
    linkedList.insertAtLinkList(20);
    linkedList.insertAtLinkList(30);
    linkedList.insertAtLinkList(40);
    linkedList.insertAtLinkList(50);
    linkedList.insertAtLinkList(60);
    linkedList.createCycleAt(30); 

    Node* cycleStartNode = linkedList.detectCycle();
    if(cycleStartNode){
        cout << "Cycle detected at node with value: " << cycleStartNode->data << "\n";
    } else {
        cout << "No cycle detected in the linked list.\n";
    }   
    return 0;
}

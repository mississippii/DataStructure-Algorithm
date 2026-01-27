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
        Node* slow = this->head;
        Node* fast = this->head;

        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = this->head;

                while(slow !=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
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
    linkedList.insertAtLinkList(70);
    linkedList.insertAtLinkList(80);
    linkedList.insertAtLinkList(90);

    linkedList.createCycleAt(4); // Creating a cycle for testing

    Node* cycleStartNode = linkedList.detectCycle();
    if(cycleStartNode){
        cout << "Cycle detected at node with value: " << cycleStartNode->data << "\n";
    } else {
        cout << "No cycle detected in the linked list.\n";
    }   
    return 0;
}

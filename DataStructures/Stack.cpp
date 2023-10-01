#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

struct stak{
    int top=0;
    int ara[100];
};

void PushIntoStack(stak * myStak,int data){
    if(myStak->top>=100){
        cout<<"Opps!! You can't Sote the value because Stack is full"<<endl;
        return;
    }
    else myStak->ara[myStak->top]=data;
    myStak->top++;
}

bool PopfromStack(stak *myStak){
    myStak->top--;
    if(myStak->top<0)return false;
    return true;
}

int TopEementOfStack(stak *myStak){
    if(myStak->top==0)return -1;
    int id= myStak->top-1;
    return myStak->ara[id];
}

int main() {
    stak myStak;
    cout<<"please tell me how many values are you want to store in this Stack : ";
    int n;
    cin>>n;
    cout<<"\nPlease Enter your values: "<<endl;
    while(n--){
        int val;
        cin>>val;
        PushIntoStack(&myStak,val);
    }
    cout<<myStak.top<<endl;
    cout<<"How many values you want to pop from Stack ?"<<endl;
    int x;
    cin>>x;
    while(x--){
        if(TopEementOfStack(&myStak)==-1)cout<<"Stack is Empty"<<endl;
        else cout<<"Top element of this stack is "<<TopEementOfStack(&myStak)<<endl;
        if(PopfromStack(&myStak))
            cout<<"Successfully pop value from stack."<<endl;
        else {
            cout<<"Sack is already empty nothing can be remove."<<endl;
            break;
        }
    }
    return 0;
}


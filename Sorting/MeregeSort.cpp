#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

//Time Complexity O(n log(n))

int temp[10000];

void  mergeSort(int Ara[],int startingIndex,int endingIndex){

    if(startingIndex==endingIndex)return ;

    int mid=(startingIndex+endingIndex)/2;

    mergeSort(Ara,startingIndex,mid);
    mergeSort(Ara,mid+1,endingIndex);

    for(int i=startingIndex,j=mid+1,k=startingIndex;k<=endingIndex;k++){

        if(i==mid+1)temp[k]=Ara[j++];
        else if (j==endingIndex+1)temp[k]=Ara[i++];
        else if (Ara[i]<Ara[j])temp[k]=Ara[i++];
        else temp[k]=Ara[j++];
    }
    for(int k=startingIndex;k<=endingIndex;k++)
        Ara[k]=temp[k];

    return;
}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int Ara[10] = {9, 3, 7, 1, 8, 5, 2, 10, 4, 6};
        mergeSort(Ara,0,9);

        for(int i=0;i<10;i++)
            cout<<Ara[i]<<" ";
        cout<<endl;

    }
    return 0;
}

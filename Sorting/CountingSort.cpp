#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

/*<--------------The time complexity of Counting Sort O(n+k) where n represent array size and
k represent the maximum value of this array----------->
NB: Array element must be non negative integer
*/

const int  maxval=10000;

int* CountingSort(int ara[], int n) {

    int maxValue = 0;
    for (int i = 0; i < n; i++)
        if (ara[i] > maxValue)
            maxValue = ara[i];

    int memo[maxValue + 1];
    RESET(memo, 0);
    for (int i = 0; i < n; i++)
        memo[ara[i]]++;
    for (int i = 1; i <= maxValue; i++)
        memo[i] += memo[i - 1];

    static int SortedArray[maxval];
    for (int i = n - 1; i >= 0; i--) {
        SortedArray[memo[ara[i]] - 1] = ara[i];
        memo[ara[i]]--;
    }

    return SortedArray;
}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int ara[10] = {90, 50, 80, 30, 10, 40, 60, 100, 20, 70};

        int* ptr = CountingSort(ara, 10);
        for (int i = 0; i < 10; i++)
            cout << ptr[i] << " ";
        cout << endl;
    }
    return 0;
}

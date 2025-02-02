#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

struct Matrix{
    int row;
    int col;
};

Matrix  matrix[3];
int memo[10][30];

int mergeCost(int left, int right,int k){
    return (matrix[left].row * matrix[k].col * matrix[right].col);
}
int getMinimumScalerOperations(int left, int right){

    if(left >= right)return memo[left][right]=0;

    if(memo[left][right]!=-1)return memo[left][right];

    int ans =INT_MAX;

    for(int k =left; k < right;k++){
        int leftCost = getMinimumScalerOperations(left, k);
        int rightCost = getMinimumScalerOperations(k+1, right);
        int cost = leftCost + rightCost + mergeCost(left,right,k);
        ans = min(ans,cost);
    }
    return memo[left][right]= ans;
}
int main() {
    matrix[0].row=10;
    matrix[0].col=5;
    matrix[1].row=5;
    matrix[1].col=50;
    matrix[2].row=50;
    matrix[2].col=20;
    RESET(memo,-1);
    int ans = getMinimumScalerOperations(0,2);
    cout<<ans<<endl;
    return 0;
}
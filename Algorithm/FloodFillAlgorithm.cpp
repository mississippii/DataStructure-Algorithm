#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

bool IsValid(int x,int y){
    bool t = false;
    return  t = ((x<8 && x>=0) && (y<8 && y>=0));
}
void FloodFill(int matrix[][8],int srcx,int srcy,int color,int paintcolor){
    
    matrix[srcx][srcy]=paintcolor;
    if(IsValid(srcx+1,srcy) && matrix[srcx+1][srcy] == color )FloodFill(matrix,srcx+1,srcy,matrix[srcx+1][srcy],paintcolor);
    if(IsValid(srcx-1,srcy) && matrix[srcx-1][srcy] == color )FloodFill(matrix,srcx-1,srcy,matrix[srcx-1][srcy],paintcolor);
    if(IsValid(srcx,srcy+1) && matrix[srcx][srcy+1] == color )FloodFill(matrix,srcx,srcy+1,matrix[srcx][srcy+1],paintcolor);
    if(IsValid(srcx,srcy-1) && matrix[srcx][srcy-1] == color )FloodFill(matrix,srcx,srcy-1,matrix[srcx][srcy-1],paintcolor);
    
    return;
}

int main() {
    int matrix[8][8] = { { 1, 1, 1, 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 1, 1, 1, 0, 0 },
                        { 1, 0, 0, 1, 1, 0, 1, 1 },
                        { 1, 2, 2, 2, 2, 0, 1, 0 },
                        { 1, 1, 1, 2, 2, 0, 1, 0 },
                        { 1, 1, 1, 2, 2, 2, 2, 0 },
                        { 1, 1, 1, 1, 1, 2, 1, 1 },
                        { 1, 1, 1, 1, 1, 2, 2, 1 } };
        int n=8;
        int m=8;
        int x = 4; // X co-ordinate value of Starting Position
        int y = 4;// y co-ordinate value of Starting Position
        int currentColor= matrix[x][y];
        int desireColor;
        cout<<"Which color(enter a int value) you want to paint and Dont enter this"<<currentColor<<" value :";
        cin>>desireColor;
        FloodFill(matrix,x,y,currentColor,desireColor);//Size of the 2D array is static thats why we didn't pass the array size as argument;

        for(int i=0 ; i<8 ; i++){
            for(int j=0 ; j<8 ; j++)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    return 0;
}

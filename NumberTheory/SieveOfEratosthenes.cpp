#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

class SieveOfEratosthenes
{
private:
    
public:
    void sieve(bool *status, int n){

        memset(status, 1, n+1);
        status[0] = false;
        status[1] = false;
        int sq = sqrt(n+1);

        for(int i=2; i<=sq;i++){
            if(status[i]){
                for(int j= i*i; j<=n; j+=i){
                    status[j] = false;
                }
            }
        }
    }
};

int main(){
    int n;
    cin>>n;
    bool status[n+1];
    SieveOfEratosthenes sieveObj;
    sieveObj.sieve(status, n);

    for(int i=0;i<=n;i++){
        if(status[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}
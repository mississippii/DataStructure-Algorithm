#include<bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

void headRecursion(int n) {
    if (n == 0) return; // Base case

    headRecursion(n - 1); // Recursive call
    cout << n << " "; // Process after recursive call
}

void tailRecursion(int n) {
    if (n == 0) return; // Base case

    cout << n << " "; // Process after recursive call
    tailRecursion(n - 1); // Recursive call
    
}

int main() {
    cout << "=== Recursion Basics ===" << endl;

    // Example: Factorial of a number
    int n = 5;
    cout << "Head Recursion of " << n << " is: ";
    headRecursion(n);
    cout << endl;
    cout << "Tail Recursion of " << n << " is: ";
    tailRecursion(n);
    cout << endl;

    return 0;
}
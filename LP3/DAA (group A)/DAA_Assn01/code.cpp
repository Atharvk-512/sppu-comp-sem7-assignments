// DAA Assn 01
// Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyze their time and space complexity.

#include <bits/stdc++.h>
using namespace std;


int fibo_rec(int n){
    if(n<0) return 0;
    if(n<=1) return n;
    return fibo_rec(n-1) + fibo_rec(n-2);
}


int fibo_itr(int n){
    if(n<0) return 0;
    if(n<=1) return n;

    vector<int> fib(n+1);
    fib[0]=0, fib[1]=1;
    for(int i=2; i<n+1; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}


int count_steps_fib_rec(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    return 1 + count_steps_fib_rec(n-1) + count_steps_fib_rec(n-2);
}


int count_steps_fib_itr(int n){
    if(n<=0) return 0;
    if(n==1) return 1;

    vector<int> steps(n+1);
    steps[0]=0, steps[1]=1;

    for(int i=2; i<n+1; i++){
        steps[i] = 1 + steps[i-1] + steps[i-2];
    }
    return steps[n];
}


vector<int> generate_fib_seq(int n){
    if(n<=0) return {};
    
    vector<int> res;
    int a=0, b=1, i=0;

    while(i<=n){
        res.push_back(a);
        int temp = a;
        a = b;
        b = temp + a;
        i++;
    }
    return res;
}


int main() {
    int n;
    cout<<"Enter number: ";
    cin>>n;

    cout<<"Fibonacci number for "<<n<<" recursively is "<<fibo_rec(n)<<endl;
    cout<<"Number of steps required in calculation of Fibonacci number for "<<n<<" recursively is "<<count_steps_fib_rec(n)<<endl;

    cout<<"Fibonacci number for "<<n<<" iteratively is "<<fibo_itr(n)<<endl;
    cout<<"Number of steps required in calculation of Fibonacci number for "<<n<<" iteraively is "<<count_steps_fib_itr(n)<<endl;

    cout<<"Fibonacci sequence for n="<<n<<" is: ";
    vector<int> fib_seq = generate_fib_seq(n);
    for(int i : fib_seq) cout<<i<<" ";
    cout<<endl;

    return 0;
}




/* OUTPUT
Enter number: 10
Fibonacci number for 10 recursively is 55
Number of steps required in calculation of Fibonacci number for 10 recursively is 143
Fibonacci number for 10 iteratively is 55
Number of steps required in calculation of Fibonacci number for 10 iteraively is 143
Fibonacci sequence for n=10 is: 0 1 1 2 3 5 8 13 21 34 55 
*/
#include <iostream>

using namespace std;

void printinator(long long n){
    while(n>1){
        cout<<n<<" ";
        if(n%2==0)
            n = n/2;
        else
            n = n*3+1;
    }
    cout<<n;
}

int main(){
    long long n;
    cin>>n;

    printinator(n);

    return 0;
}
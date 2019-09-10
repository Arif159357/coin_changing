#include <iostream>
using namespace std;
int Array(int* &A, int x){
    A=new int[x];
}
void populater(int *A, int x){
    cout<<"Give me the amount of each coin :-"<<endl;
    for(int i=0; i<x; i++){
        cout<<"Coin "<<i<<"->";
        cin>>A[i];
    }
    cout<<endl;
}
void print(int *A, int x){
    cout<<"coins value"<<endl;
    for(int i=0; i<x; i++){
        cout<<"Coin "<<i<<"->"<<A[i]<<endl;

    }
    cout<<endl;
}
void method(int *S, int n, int *A){

    while(n!=0){
        int a=S[n];
        cout<<" "<<A[a];
        n=n-A[a];
    }

}
void Coin_Changing(int *A, int n, int x){
    int M[n];
    int S[n];
    M[0]=0;
    S[0]=0;

    for(int p=1; p<n; p++){
        int min=999;
        int coin=999;
        for(int i=0; i<x; i++){
            if(A[i]<=p){
                int v=M[p-A[i]];
                if(1+v<min){
                    min=1+v;
                    coin=i;
                }
            }
        }
    if(min!=999){
        M[p]=min;
        S[p]=coin;
    }
    else{
        M[p]=0;
        S[p]=0;
    }
}
    cout<<endl<<endl;
    cout<<"Minimum coins neede for each amount :-"<<endl;
    for(int p=0; p<n; p++){
        cout<<" "<<M[p];
    }
    cout<<endl<<endl;
    cout<<"Which coins are used:-"<<endl;
    for(int p=0; p<n; p++){
        cout<<" "<<S[p];
    }
    cout<<endl<<endl;

    cout<<"Minimum coin needed for "<<n-1<<" is "<<M[n-1]<<" and the coins are ";
    method(S,n-1,A);
    cout<<endl;

}

int main()
{
    int x,z,n;
    int *A;
    cout<<"How many coins do you need:-";
    cin>>x;
    cout<<"For what amount do you need change:-";
    cin>>z;
    n=z+1;
    Array(A,x);
    populater(A,x);
    print(A,x);
    Coin_Changing(A,n,x);
    return 0;
}

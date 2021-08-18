#include<iostream>
#include<math.h>
using namespace std;

int factorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }else{
    return n*factorial(n-1);
    }
}

void pascalTriange(int n){

    // PASCALS TRAIANGLE
    // ICJ WHERE I IS THE ROW NUMBER AND J IS THE COLUMN NUMBER AND J<=I

    int a;
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= i;j++){
            a = factorial(i)/(factorial(j) * factorial(i-j));
            cout<<a<<" ";
        }
        cout<<"\n";
    }
}

void reverse(){
    int a;
    cin>>a;
    int reverse = 0;
    while(a != 0){
        int temp = a%10;
        reverse = reverse*10  + temp;
        a = a/10;
    }
    cout<<reverse;
}

bool check(int x, int y, int z){
    int a;
    a = max(x, max(y, z));
    if (a == x){
        if (x < y + z && pow(x,2) == pow(y,2) + pow(z,2)){
            return true;
        }
        else return false;
    }
    else if (a == y){
        if (y < x + z && pow(y,2) == pow(x,2) + pow(z,2)){
            return true;
        }
        else return false;
    }
    else{
        if (z < y + x && pow(z,2) == pow(y,2) + pow(x,2)){
            return true;
        }
        else return false;
    }
}

void pythagorusCheck(){
    int x, y, z;
    cin>>x>>y>>z;
    cout<<check(x, y, z);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // reverse();
    // pascalTriange(5);
    pythagorusCheck();

    return 0;
}
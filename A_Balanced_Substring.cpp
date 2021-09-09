#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.length() == 1){
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    int n1=0, n2=0;
    int l=-1, r=-1;
    for(int i=0;i<n;i++){
        if(s[i] == 'a'){
            n1++;
            if(n1 == 1 && n2 == 1){ // b already encountered
                cout<<l<<" "<<i+1<<endl;
                return;
            }
            if(n1 == 1 && n2 == 0){ // b not yet encountered
                l = i + 1;
            }
            if(n1 > 1){
                if(i<n-1 && s[i+1] == 'b'){
                    cout<<i+1<<" "<<i+2<<endl;
                    return;
                }
                else{
                    n1 == 0;
                }
            }
        }
        else if(s[i] == 'b'){
            n2++;
            if(n2 == 1 && n1 == 1){ // a already encountered
                cout<<l<<" "<<i+1<<endl;
                return;
            }
            if(n2 == 1 && n1 == 0){ // a not yet encountered
                l = i + 1;
            }
            if(n2 > 1){
                if(i<n-1 && s[i+1] == 'a'){
                    cout<<i+1<<" "<<i+2<<endl;
                    return;
                }
                else{
                    n2 == 0;
                }
            }
        }
    }
    cout<<-1<<" "<<-1<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
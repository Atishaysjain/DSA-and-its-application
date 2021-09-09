#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int n0 = 0, n1 = 0;
    for(int i = 0;i<n;i++){
        if(s[i] == '1'){n0 += 1;}
        else{n1 += 1;}
    }
    if(n1 == 1 || n1 == 2){ // n1 :- number of 2's
        cout<<"NO"<<endl;
        return;
    }
    // 1 2 1 2
    int num_col = n;
    int num_row = n;
    vector<char> row(num_col, '*');
    vector<vector<char>> v(num_row, row) ;

    for(int i=0;i<s.length();i++){ // traversing through the rows
        for(int j=0;j<s.length();j++){ // traversing through the columns
            if(v[i][j] == '*'){
                if(i == j){v[i][j] = 'X';}
                else if(s[i] == '1' || s[j] == '1'){
                    v[i][j] = '=';
                    v[j][i] = '=';
                }
                else if(i < n/2){
                    if(j == n-1-i){v[i][j] = '+';v[j][i] = '-';}
                    else{v[i][j] = '-';v[j][i] = '+';}
                }
                else if(i >= n/2){
                    v[i][j] = '-';
                    v[j][i] = '+';
                }
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j];
        cout<<endl;
    }
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
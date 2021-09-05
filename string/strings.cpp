#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void maxLetterOccurance();

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // string creation and taking input
    string str1(7, 'a');
    cout<<str1<<endl;

    string str2;
    getline(cin, str2); // would also take words after space
    cout<<str2<<endl;
    
    // concatenating, comparing, deleting and checking if a string is empty
    string s1 = "ati";
    cout<<s1[0]<<endl;
    string s2 = "shay";
    cout<<s1+s2<<endl;
    cout<<s1.compare(s2)<<endl;
    s1.append(s2);
    cout<<s1<<endl;
    cout<<s1.compare(s2)<<endl;
    s1.clear();
    cout<<s1<<endl;
    cout<<s1.empty()<<endl; // Would tell weather the string is empty
    
    string s3 = "nincompoop";
    cout<<s3.find("poo")<<endl;
    s3.erase(3,2); // remove 2 charecters from index 3
    cout<<s3<<endl;

    // insertion
    string s4 = "atishay";
    s4.insert(7,"lol");
    cout<<s4<<endl;
    cout<<s4.size()<<endl;
    string s5 = s4.substr(0, 7);
    cout<<s5<<endl;

    // datatype conversion
    string s6 = "911";
    int a = stoi(s6); // string to integer
    cout<<a+1<<endl;
    s6 = to_string(a); // converting to string
    cout<<s6<<endl;

    // Converting lower case to upper case 
    string name = "atishay";
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    cout<<name<<endl;
    name = "atishay";
    for(int i = 0;i < name.size(); i++){
        if(name[i] >= 'a' && name[i] <= 'z'){
            name[i] -= 32;
        }
    }
    cout<<name<<endl;

    // Converting upper case to lower case 
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    cout<<name<<endl;
    name = "ATISHAY";
    for(int i = 0;i < name.size(); i++){
        if(name[i] >= 'A' && name[i] <= 'Z'){
            name[i] += 32;
        }
    }
    cout<<name<<endl;

    // sorting
    sort(name.begin(), name.end());
    cout<<name<<endl;
    sort(name.begin(), name.end(), greater<int>());
    cout<<name<<endl;

    maxLetterOccurance();

    return 0;
}

void maxLetterOccurance(){
    string str;
    cin>>str;
    int freq[26];
    for(int i=0;i<26;i++){
        freq[i] = 0;
    }
    for(int i=0;i<str.size();i++){
        freq[str[i] - 'a'] += 1;
    }
    int maxFrequency = 0;
    char ans;
    for(int i=0;i<str.size();i++){
        maxFrequency = max(maxFrequency, freq[str[i] - 'a']);
        if(maxFrequency == freq[str[i]]){
            ans = str[i];
        }
    }
    cout<<ans<<" "<<maxFrequency<<endl;
}
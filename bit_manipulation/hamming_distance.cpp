// Given an array of non negetive binary numbers find the sum of hamming distances between all it's numbers

// Brute force approach :- 
// string to_binary(int n);
// int difference(string a, string b); 

// int Solution::hammingDistance(const vector<int> &A) {
//     int maximum = 0;
//     for(int i=0;i<A.size()-1;i++){
//         for(int j=i+1;j<A.size();j++){
//             maximum += difference(to_binary(A[i]), to_binary(A[j]));
//         }
//     }
//     return maximum;
// }
// string to_binary(int n){ // gives binary representation of a decimal
    
//     if(n==0){
//         return 0;
//     }
//     else{
//         string binary;
//         while(n!=0){
//             binary.append(to_string(n%2));
//             n /= 2;
//         }
//         reverse(binary.begin(), binary.end());
//         return binary;
//     }
// }

// int difference(string a, string b){ // returns the hamming distance between binary representations

//     reverse(a.begin(), a.end());
//     reverse(b.begin(), b.end());
//     int diff = 0;
//     int minimum = min(a.size(), b.size());
//     for(int i=0;i<minimum;i++){
//         if(a[i] != b[i]){
//             diff++;
//         }
//     }

//     if(minimum == a.size()){
//         for(int i=a.size();i<b.size();i++){
//             if(b[i] == '1'){
//                 diff++;
//             }
//         }
//     }
//     else{
//         for(int i=b.size();i<a.size();i++){
//             if(a[i] == '1'){
//                 diff++;
//             }
//         }
//     }
//     return diff;
// }

int Solution::hammingDistance(const vector<int> &A) {
    long int compare; // will be used to tell weather one is present or 0 is present at a given position
    int n1 = 0; // number of 1's present at a given position 
    int n0 = 0; // number of 0's present at a given position
    long int sum = 0; // total hamming distance
    int mod = 1000000007;
    for(int i=0;i<32;i++){
        compare = 1<<i;
        n1 = 0;
        n0 = 0;
        for(int j=0;j<A.size();j++){
            if(compare & A[j]){
                n1 += 1;
            } 
            else{
                n0 += 1;
            }
        }
        sum = (sum + (2*n1*n0)%mod)%mod;
    }
    return sum;
}
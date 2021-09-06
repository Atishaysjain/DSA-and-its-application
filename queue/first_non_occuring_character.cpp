// link :- https://www.interviewbit.com/old/problems/first-non-repeating-character-in-a-stream-of-characters/

// Problem Description

// Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

// B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.



// Problem Constraints
// 1 <= length of the string <= 100000



// Input Format
// The only argument given is string A.



// Output Format
// Return a string B after processing the stream of lowercase alphabets A.



// Example Input
// Input 1:

//  A = "abadbc"
// Input 2:

//  A = "abcabc"


// Example Output
// Output 1:

//  "aabbdd"
// Output 2:

//  "aaabc#"


// Example Explanation
// Explanation 1:

//     "a"      -   first non repeating character 'a'
//     "ab"     -   first non repeating character 'a'
//     "aba"    -   first non repeating character 'b'
//     "abad"   -   first non repeating character 'b'
//     "abadb"  -   first non repeating character 'd'
//     "abadbc" -   first non repeating character 'd'
// Explanation 2:

//     "a"      -   first non repeating character 'a'
//     "ab"     -   first non repeating character 'a'
//     "abc"    -   first non repeating character 'a'
//     "abca"   -   first non repeating character 'b'
//     "abcab"  -   first non repeating character 'c'
//     "abcabc" -   no non repeating character so '#'


// Approach :- 

// We can do this using queue data structure and an hash array of size 26.

// -> Create a count array of size 26(assuming only lower case characters are present) and initialize it with zero.
// -> Create a queue of char datatype.
// -> Store each character in queue and increase its frequency in the hash array.
// -> For every character of stream, we check front of the queue.
// -> If the frequency of character at the front of queue is one, then that will be the first non repeating character.
// -> Else if frequency is more than 1, then we pop that element.
// -> If queue became empty that means there are no non repeating character so we will append #.

// Solution :- 

string Solution::solve(string A) {
    
    string result = "";
    queue<char> q;
    vector<int> arr(26, 0); // this will store the number of times the letter corresponding to a particular index has been seen encountered the string A
    for(int i=0;i<A.length();i++){
        if(i == 0){
            result += A[i];
            q.push(A[i]);
            arr[A[i] - 'a'] += 1;
        }
        else{
            if(result[i-1] == A[i]){
                arr[A[i] - 'a'] += 1;
                q.pop();
                if(q.empty()){
                    result += "#";
                }
                else{
                    bool flag = true;
                    while(true){
                        if(q.empty()){
                            result += "#";
                            break;
                        }
                        if(arr[q.front()-'a'] > 1){q.pop();}
                        else{
                            result += q.front();   
                            flag = false;
                            break;
                        }
                    }
                    // if(flag){result += "#";}
                }
            }    
            else{
                if(result[i-1] == '#'){
                    result += A[i];
                }else{result += result[i-1];}
                q.push(A[i]);
                arr[A[i] - 'a'] += 1;
            }
        }
    }
    return result;
}
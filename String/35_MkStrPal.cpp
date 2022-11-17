// Minimum characters to be added at front to make string palindrome
// https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
#include<iostream>
using namespace std;
// these function check weather the stris palidrome or not
bool isPalindrome(string str){
    int i=0;
    int j=str.length()-1;
while(i<=j){
    if(str[i]!=str[j]) return 0;
    i++;
    j--;
}
    return 1;
}

int main(){
    string str="ABC";
    int flag=0;
    int count=0;
    for(int i=str.length();i>0;i--){
        // when string get pal or single char is remain then if block exicuted
        if(isPalindrome(str)){
            flag=1;
            break;
        }
        else{
            count++;
            // if not pal then increse count and erase last char of str
            str.erase(str.begin()+str.length()-1);
        }
    }
    // return count 
        if(flag){
            cout<<count;
        }
    return 0;
}
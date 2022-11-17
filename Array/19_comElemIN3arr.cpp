// find common elements In 3 sorted arrays
// https://practice.geeksforgeeks.org/problems/common-elements1132/1#

/*
Two approches:
1st -> 
    TC: O(n1+n2+n3)
    SC: O(n1+n2+n3)
    By using hash map use three separate map to maintain array elemnt 
    this approch works unexpectly on gfg
2nd ->
    TC: O(n1+n2+n3)
    SC: O(1)
    use three var i j k 

*/
#include<bits/stdc++.h>
using namespace std;

// 1st Approch ->
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            unordered_map<int,int> mp1,mp2,mp3;
            vector<int> ans;
            int s=max(n1,max(n2,n3));
            for(int i=0;i<s;i++){
                if(i<=n1){
                    mp1[A[i]]++;
                }
                if(i<=n2){
                    mp2[B[i]]++;
                }
                if(i<=n3){
                    mp3[C[i]]++;
                }
            }
            for(int i=0;i<n1;i++){
             if(mp1[A[i]] and mp2[A[i]] and mp3[A[i]]){
                ans.push_back(A[i]);
                mp1[A[i]]=0;
                 
             }
            }
            return ans;
        }

// 2nd Approch ->
vector <int> commonElements2 (int A[], int B[], int C[], int n1, int n2, int n3)
        {

            vector<int> ans;
            int i=0,j=0,k=0;
            while(i<n1 and j<n2 and k<n3){
                if(A[i]==B[j] and B[j]==C[k]){
                    ans.push_back(A[i]);
                    j++;i++;k++;
                }
                // due to only sorted order these works
                else if(A[i]<B[j]) i++;
                else if(B[j]<C[k]) j++;
                else k++;
                // for corner case like 
                //  3 3 3
                //  3 3 3
                //  3 3 3
                int x=A[i-1];
                while(A[i]==x)i++;
                int y=B[j-1];
                while(B[j]==y)j++;
                int z=C[k-1];
                while(C[k]==z)k++;
            }
            return ans;
        }

int main(){
          
  return 0;
}
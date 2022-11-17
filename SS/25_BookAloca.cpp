#include<bits/stdc++.h>
using namespace std;

        
class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool canAllocate(int A[],int N,int M,int mid){
        
        int currStud=1;
        int currSum=0;
        for(int i=0;i<N;i++){
            if(A[i]>mid) return 0;
            currSum+=A[i];
            if(currSum>mid){
                currSum=0;
                currStud++;
                i--;
            }
            if(currStud>M){
                return false;
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int totalPages=0;
        if(M>N) return -1;
       for(int i=0;i<N;i++){
           totalPages+=A[i];
       }
       
       int lo=0;
       int hi=totalPages;
       int minPages=INT_MAX;
       int mid;
       while(lo<=hi){
           mid=(lo+hi)/2;
           
           if(canAllocate(A,N,M,mid)){
               
               hi=mid-1;
           }
           else{
               lo=mid+1;
           }
       }
       if(canAllocate(A,N,M,lo)) return lo;
       else return hi ;
    }









    class Solution2 
{
    public:
    //Function to find minimum number of pages.
    bool canAllocate(int A[],int N,int M,int mid){
        
        int currStud=1;
        int currSum=0;
        for(int i=0;i<N;i++){
            if(A[i]>mid) return 0;
            currSum+=A[i];
            if(currSum>mid){
                currSum=0;
                currStud++;
                i--;
            }
            if(currStud>M){
                return false;
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int totalPages=0;
        if(M>N) return -1;
       for(int i=0;i<N;i++){
           totalPages+=A[i];
       }
       
       int lo=0;
       int hi=totalPages;
       int minPages=INT_MAX;
       while(lo<=hi){
           int mid=(lo+hi)/2;
           
           if(canAllocate(A,N,M,mid)){
               
               minPages=min(minPages,mid);
               
               hi=mid-1;
           }
           else{
               lo=mid+1;
           }
       }
       return minPages;
    }
};
    int main(){
          
  return 0;
}
};
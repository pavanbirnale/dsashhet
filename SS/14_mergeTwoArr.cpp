// merge two sorted arrays
// merge 2 sorted arrays
// Merge Without Extra Space 
// Merge two sorted arrays with O(1) extra space
#include<bits/stdc++.h>
using namespace std;


//insertion sort like approch
// TC: O(N*M)
void merge1(int arr1[],int arr2[],int n,int m){
    for(int i=m-1;i>=0;i--){
        // peek last elemrt of array1 ang shipt the loop hole toward left untill arr1[j]>arr2[i]
        int last=arr1[n-1];
        int j;
        for(j=n-2;j>=0 and arr1[j]>arr2[i];j--){
            // here is shipting of loop hole
            arr1[j+1]=arr1[j];
        }
        // if shipting not happend or j<0 or last is smaller than arr[i] then noting to do
        if(j!=n-2 && last>arr2[i]){
            swap(arr1[j+1],arr2[i]);
            arr2[i]=last;
        }
    }
}


//Optimal solution
// TC: O(N+M) for traversing and O(NlogN) + O(MlogM) for sorting so overall is
// O((N+M)log(N+M))

void merge2(int arr1[],int arr2[],int n,int m){

    /* define three variables :
    i for traversing over arr1 from left to right
    j for traversing over arr2 from left to right
    k for traversing over arr2 from right to left untill overcome of i

   */
    int i=0;int j=0; int k=n-1;
    // traverse loop untill i and k not overcome each other and j<m
    while(i<=k and j<m){

        // here check is arr1 element is leass than arr2 element then incresse i
        // 
        if(arr1[i]<arr2[j]){
            i++;
        }
        //else in arr2 jth element must be present in arr1 becuase it is less than curr ith element
        //  so we replace curr jth element with largest elemt of arr1 that meanse kth element
        // and then increse j and decreese k 
        else{
            swap(arr2[j],arr1[k]);
            j++;
            k--;
        }
    }
    // After that sort the arrays
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}
           
int main(){
int arr1[] ={1, 3, 5, 7};
int arr2[] = {0, 2, 6, 8, 9};
merge2(arr1,arr2,4,5);

for(int i=0;i<4;i++){
    cout<<arr1[i]<<" ";
}
for(int i=0;i<5;i++){
    cout<<arr2[i]<<" ";
}
  return 0;
}
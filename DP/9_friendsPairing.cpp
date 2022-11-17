// Friends Pairing Problem
// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#
// https://www.youtube.com/watch?v=SHDu0Ufjyk8&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=28
//  image 1 : https://res.cloudinary.com/darshanscloud/image/upload/v1643262764/aapzeaxe0jvcjia6m2y9.png
//  image 2 : https://res.cloudinary.com/darshanscloud/image/upload/v1643262716/krqaeiw0g5svxu7ckzhp.png

/*
In this problem what we have to do is tell the count of ways by which the friends can combines to form pair

we use formula 
dp[i] = dp[i-1] + dp[i-2] * (i-1);
as shown in image 1 for 1234 : 
1 can go separate and call to (i-1) ie. 234 an forms pairs 2-3-4,2-34,23-4,234,24-3 
similarly 1 will form pair with 2,3,4 as 12,13,14 respectively
that is (i-1) pairs with (i-2)
*/
 
 
#include<bits/stdc++.h>
using namespace std;
           
int friendsPairing(int n){
    vector<int> dp(n+1);
    // one friend can form only one pair
    dp[1]=1;

    // two friends can form at most two pairs
    dp[2]=2;
    
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }
    return dp[n];
}
           
int main(){
      cout<<friendsPairing(3);
  return 0;
}

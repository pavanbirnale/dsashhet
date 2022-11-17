// Paint House 2 (Many Colors)
/*

see video if not undersand https://www.youtube.com/watch?v=jGywRalvoRw&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=24

This problem is an extention of previous problem paint house where the number of colores are only 3 but here we have N colors

The logic of solving is pretty similar like that  
In that problem we add min among the remaining to columns 
But in this problem we have to add remaining from all other colors-1 columns


Approches 2 : 

1. Dp with TC O(colors^3);
2. Dp with TC O(colors^2);
*/
#include<bits/stdc++.h>
using namespace std;



// Approach 2 TC O(n^3);

int paintHouse2(vector<vector<int>> costs,int colors){

    // here we are creating another dp table rather than that we can use given cost vector also

    vector<vector<int>> dp(costs.size(),vector<int>(colors,0));
    int least = INT_MAX;
    // base case for 1st row that is ass it is cost[0][k]
    for(int i=0;i<colors;i++){
        dp[0][i] = costs[0][i];
    }

  // first loop for iterating over cost array rows
    for(int i=1;i<costs.size();i++){
        // iterating over columns of each row
        for(int j=0;j<colors;j++){
            least = INT_MAX;
            // finding minmum from previous row
            for(int k=0;k<colors;k++){
                if(k!=j) least = min(least,dp[i-1][k]);
            }
            // seting value that curr cost  + previous min cost
            dp[i][j] = costs[i][j] + least;
        }
    }
    least=INT_MAX;

    // loop for finding minimum is last row of dp table
     for(int k=0;k<colors;k++){
        least = min(least,dp[costs.size()-1][k]);
    }


    // loop for printing dp table
    for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp[0].size();j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
    }
    return least;
}









// Approach 1 TC O(O^2) efficient; 
// In the above approach we uses another extra ks loop for finding min from each previous columns
// we can optimize that by maintains lest and second least while inserting in second loop of j 


int paintHouse2Optimize(vector<vector<int>> costs,int colors){

    // here we are creating another dp table rather than that we can use given cost vector also

    vector<vector<int>> dp(costs.size(),vector<int>(colors,0));

    int least = INT_MAX;
    int sleast = INT_MAX;

// this loop is for base case and that also gives us the least and the second least
    for(int i=0;i<colors;i++){
        dp[0][i] = costs[0][i];

        if(dp[0][i]<=least){
            sleast =least;
            least = dp[0][i];
        }
        else if(dp[0][i]<=sleast){
            sleast = dp[0][i];
        }
    }

    for(int i=1;i<costs.size();i++){
        int nleast = INT_MAX;
        int nsleast = INT_MAX;
        for(int j=0;j<colors;j++){

            if(least != dp[i-1][j]){
                dp[i][j] = costs[i][j] + least;
            }
            else{
                dp[i][j] = costs[i][j] + sleast;
            }

            if(dp[i][j]<=nleast){
                nsleast = nleast;
                nleast = dp[i][j];
            }
            else if(dp[i][j]<=nsleast){
                nsleast = dp[i][j];
            }
        }
        least = nleast;
        sleast = nsleast;
    }
    least = INT_MAX;
     for(int i=0;i<costs.size();i++){
        least = min(least,dp[costs.size()-1][i]);}

   for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
    cout<<endl;
    }
    return least;
}

int main(){
    vector<vector<int>> cost =  
    {{1,5,7}, 
    {5,8,4},
    {3,2,9},
    {1,2,4}
    };
    cout<<paintHouse2(cost,3);
    cout<<endl;
    cout<<paintHouse2Optimize(cost,3);
  return 0;
}
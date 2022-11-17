#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // dp of more size program not work
    int dp[10][10];


public:
    int amin(int x, int y, int z) { return min(min(x, y), z); }
    int editDist(string s, string t, int s1, int t1)
    {
        // if pointer at s1 goes to zero then insert all the chars of s t1 + 1 due to zero base index
        if (s1 == -1) 
            return t1 + 1;

        // if pointer at t1 goes to zero then insert all the chars of t t1 + 1 due to zero base index
        if (t1 == -1)
            return s1 + 1;

        if (dp[s1][t1] != -1)
            return dp[s1][t1];

        // if both chars are same then nothing to do
        if (s[s1] == t[t1])
            return dp[s1][t1] = editDist(s, t, s1 - 1, t1 - 1);

        return dp[s1][t1] = 1 + amin(
                                    editDist(s, t, s1, t1 - 1), //insert
                                    editDist(s, t, s1 - 1, t1), //remove
                                    editDist(s, t, s1 - 1, t1 - 1)); //replace
    }

public:
    int editDistance(string s, string t)
    {
        memset(dp, -1, sizeof(dp));
        int s1 = s.length();
        int t1 = t.length();
        return editDist(s, t, s1 - 1, t1 - 1);
    }
};

int main()
{
    Solution s1;
    string s="geek";
    string t="gesek";
    cout << s1.editDistance(s,t);
    return 0;
}

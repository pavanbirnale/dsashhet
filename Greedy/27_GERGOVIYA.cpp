// GERGOVIA - Wine trading in Gergovia
// this is spoj problem
/*
Gergovia consists of one street, and every inhabitant of the city is a wine salesman. Everyone buys wine from other inhabitants of the city. Every day each inhabitant decides how much wine he wants to buy or sell. Interestingly, demand and supply is always the same, so that each inhabitant gets what he wants.

There is one problem, however: Transporting wine from one house to another results in work. Since all wines are equally good, the inhabitants of Gergovia don't care which persons they are doing trade with, they are only interested in selling or buying a specific amount of wine.

In this problem you are asked to reconstruct the trading during one day in Gergovia. For simplicity we will assume that the houses are built along a straight line with equal distance between adjacent houses. Transporting one bottle of wine from one house to an adjacent house results in one unit of work.
*/

// /here what we have to do is minimize the total work 

#include <bits/stdc++.h>
#define int long long int
using namespace std;
 
void solve()
{
 
    int n;
    cin >> n;
    while (true)
    {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<pair<int, int>> buy, sell;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                buy.push_back({arr[i], i});
            else
            {
                sell.push_back({arr[i], i});
            }
        }
        int ans = 0, i = 0, j = 0;
        while (i < buy.size() and j < sell.size())
        {
            int x = min(buy[i].first, -sell[j].first);
            int diff = abs(buy[i].second - sell[j].second);
            ans += (x * diff);
            buy[i].first -= x;
            sell[j].first += x;
            if (buy[i].first == 0)
                i++;
            if (sell[j].first == 0)
                j++;
        }
        cout << ans << endl;
        cin >> n;
        if (n == 0)
            break;
    }
 
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
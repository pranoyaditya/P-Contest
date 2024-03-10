#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mod = 1e9+7;

ll top_down_subset_sum(ll n, ll target, vector<ll>&arr, vector<vector<ll>>&dp)
{
    if(n == 0)
    {
        return target == 0;
    }

    if(dp[n][target] != -1) return dp[n][target];

    if(arr[n-1] <= target)
    {
        return dp[n][target] = (top_down_subset_sum(n-1,target-arr[n-1],arr,dp) + top_down_subset_sum(n-1,target,arr,dp))%mod;
    }
    else return dp[n][target] = top_down_subset_sum(n-1,target,arr,dp)%mod;
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll n,d,total=0;
        cin >> n >> d;

        vector<ll> arr(n);

        for(ll i=0; i<n; i++)
        {
            cin >> arr[i];
            total += arr[i];
        }

        if((total-d)<0 || (total-d)%2==1) cout << "0\n";
        else
        {
            ll target = (total-d)/2;
            vector<vector<ll>> dp(n+1,vector<ll>(target+1,-1));
        
            cout << top_down_subset_sum(n,target,arr,dp) << "\n";
        }
    }

    return 0;
}
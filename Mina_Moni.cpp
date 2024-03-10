#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll mini;

void minimumDiff(ll n, ll total, ll mid, ll arr[], vector<ll>&vOfmina)
{
    if((ll)vOfmina.size() == mid)
    {
        ll sum = 0;

        for(ll val : vOfmina)
        {
            sum += val;
        }

        ll s1 = total-sum;

        mini = min(mini,abs(sum-s1));
        return;
    }

    if(n<=0 || (ll)vOfmina.size()+n < mid) return;

    vOfmina.push_back(arr[n-1]);
    minimumDiff(n-1,total,mid,arr,vOfmina);

    vOfmina.pop_back();
    minimumDiff(n-1,total,mid,arr,vOfmina);
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        mini = 1e15+7;

        cin >> n;

        ll total = 0;
        ll arr[n];

        for(ll i=0; i<n; i++)
        {
            cin >> arr[i];
            total += arr[i];
        }

        ll mid = n/2;
        vector<ll> vOfmina;

        minimumDiff(n,total,mid,arr,vOfmina);

        cout << mini << "\n";
    }

    return 0;
}
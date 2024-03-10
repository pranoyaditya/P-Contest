#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isZeroPresent(ll l, ll r, vector<ll>&zeroIndx)
{
   for(ll indx : zeroIndx)
   {
        if(indx>= l && indx<=r) return true;
   }
   return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll>preMul(n+1);
    vector<ll> zeroIndx;
    preMul[0]=1;

    for(ll i=0; i<n; i++)
    {
        ll x;
        cin >> x;

        if(x!=0) preMul[i+1] = preMul[i]*x;
        else 
        {
            preMul[i+1] = 1;
            zeroIndx.push_back(i+1);
        }
    }

    ll q;
    cin >> q;

    sort(zeroIndx.begin(),zeroIndx.end());

    while(q--)
    {
        ll l,r;
        cin >> l >> r;

        bool found = isZeroPresent(l,r,zeroIndx);

        if(found) cout << "0\n";
        else cout << (preMul[r]/preMul[l]) << "\n";
    }

    return 0;
}
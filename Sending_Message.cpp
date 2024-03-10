#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    while(true)
    {
        string a,b;
        cin >> a >> b;

        int i = a.size(), j = b.size();
        string ans;

        while(i!=0 && j!=0)
        {
            if(a[i-1] == b[j-1])
            {
                ans += a[i-1];
                i--;
                j--;
            }
            else i--;
        }

        reverse(ans.begin(),ans.end());

        if(ans == b) cout << "Possible\n";
        else cout << "Impossible\n";

        if(cin.eof()) break;
    }


    return 0;
}
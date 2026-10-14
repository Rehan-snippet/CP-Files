#include <bits/stdc++.h>
using namespace std;

// ----------------------
// Type Aliases
// ----------------------
using ll = int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    ll v[n+1];
    ll sz= 450;
    ll table[sz][sz];
    memset(table, 0, sizeof(table));
    memset(v, 0, sizeof(v));

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            if(b>=sz){
                for(ll i=a; i<=n; i+=b) v[i]+=c;
            }
            else table[b][a]+=c;
        }
        else
        {
            ll d, temp=0;
            cin >> d;
            for(ll i=1; i<sz; i++){
                temp+= table[i][d%i];
            }
            cout<<v[d]+temp<<"\n";
        }
    }

    return 0;
}
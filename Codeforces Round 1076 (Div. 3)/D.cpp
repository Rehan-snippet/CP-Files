#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ull unsigned long long
#define lll __int128
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define loop2(i,n) for(ll i=1;i<=n;i++)
#define input(a) for(auto &x:a) cin>>x
#define output(a) for(auto x:a) cout<<x<<" ";cout<<endl
#define endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define pi 3.14159265358979323846LL

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl a(n), b(n);
        input(a); input(b);
        sort(all(a));
        ll big=-1; set<ll> s;
        loop(i,n){
            s.insert(a[i]);
            big=max(big, a[i]);
        }

        vl swords, level;
        level.pb(n); swords.pb(b[0]);
        for(ll i=1; i<n; i++){
            if(a[i]==a[i-1]) continue;
            else level.pb(n-i);
        }

        ll idx=1;
        while(swords[idx-1]+b[idx]<=n) swords.pb(swords[idx-1]+b[idx++]);

        vl p(n+1,0);
        loop2(i,n){
            p[i]=p[i-1]+b[i-1];
        }
        //idx--;
        // output(swords);
        // output(level);
        ll score=0, i=0;

        loop(i,n){
            ll f=n-i;
            auto it= upper_bound(all(p), f);
            ll x= it-p.begin()-1;
            score= max(score, a[i]*x);
        }
        cout<<score<<endl;
        
    }
    
    return 0;
}
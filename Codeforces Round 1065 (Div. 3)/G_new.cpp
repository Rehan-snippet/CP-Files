#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ld long double
#define ull unsigned long long
#define lll __int128
#define vl vector<ll>
#define pb push_back
#define loop(i,n) for(int i=0;i<n;i++)
#define input(a) for(auto &x:a) cin>>x;
#define output(a) for(auto x:a) cout<<x<<" ";
#define endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define pi 3.14159265358979323846L

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl p(n);
        vector<pair<ll,ll>> edge;
        input(p);
        string ans="Yes";
        vl num;
        ll i,mini=p[0];

        for(i=1; i<n; i++){
            if(p[i]<mini){
                num.pb(p[i]);
            }
            else{
                edge.pb({p[i],mini});
                for(auto x:num){
                    edge.pb({p[i],x});
                    mini=min(mini,x);
                }
                num.clear();
            }
        }
        if(num.size()) ans="No";

        cout<<ans<<endl;
        if(ans=="Yes"){
            for(auto x:edge){
                cout<<x.first<<" "<<x.second<<endl;
            }
        }
    }
    
    return 0;
}
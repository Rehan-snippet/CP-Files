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
// sort(all(b), [&](int x, int y) {return a[x] < a[y];});

int main() {
    fastio;
    test{
        ll n,m;
        cin>>n>>m;
        vl a(n), b(n);
        vector<pair<ll,ll>> ans;
        input(a);
        loop(i,n) b[i]=i;
        sort(all(b), [&](int x, int y) {return a[x] < a[y];});
        
        int sum=0;
        loop(i,n-1){
            sum+=a[b[i]];
        }

        if(m> n/2 || a[b[n-1]]>sum) cout<<-1<<endl;
        else{
            ll idx=n-1, t=0;
            while(m-t>0){
                ans.pb({b[idx]+1, b[t]+1});
                t++; idx--;
            }
            for(ll i=t; i<idx; i++){
                ans.pb({b[i]+1,b[i+1]+1});
            }

            // for(ll i=n-1; i>n-1-m; i--){
            //     cout<<b[i]+1<<" "<<b[i-m]+1<<endl;
            // }
            // for(ll i=0; i<n- 2*m-1; i++){
            //     cout<<b[i]+1<<" "<<b[i+1]+1<<endl;
            // }

            for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;
            cout<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}
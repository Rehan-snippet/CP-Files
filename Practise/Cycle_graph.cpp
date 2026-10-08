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
#define input(a) for(auto &x:a) cin>>x;
#define output(a) for(auto x:a) cout<<x<<" ";cout<<endl;
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
        vl p(n+1),adj(n+1);
        vector<pair<ll,ll>> ans;
        loop2(i,n) cin>>p[i];
        loop2(i,n){
            adj[p[i]]=i;
        }
        //output(adj);
        ll start=adj[1], t=-1, counter=0;
        for(ll i=1; i<=n; i++){
            ll f=adj[i], l=adj[f], s=l; adj[i]=-1, adj[f]=-1;
            while(l!=-1){
               // if(s!=l) adj[s]=-1;
                s=l;
                l=adj[l];
                adj[s]=-1;
                //counter++;
                
            }
            if(t!=-1) ans.pb({f,t});
            while(adj[i]==-1) i++;
            i--;
            t=s;
            counter++;
        }
        if(counter>1) ans.pb({start,t});

       
        cout<<ans.size()<<endl;
        loop(i,ans.size()){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        //cout<<counter;
        //cout<<endl;
        

    }
    
    return 0;
}
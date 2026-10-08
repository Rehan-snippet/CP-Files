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
#define MOD 998244353
// memset(a, -1, sizeof(a));

pair<ll,ll> cost(ll a,ll b){
    if(a==b) return {0,a};
    else if(a==2 && b==1) return{1,2};
    else if(a==3 && b==1) return{3,1};
    else if(a==b+1 && b%2) return {1,a};
    else if(a%2==1) return {2+cost(max((a+1)/2,b), min((a+1)/2 ,b)).first ,cost(max((a+1)/2,b), min((a+1)/2 ,b)).second} ;
    else if(b%2) return {1+cost(a,b+1).first, cost(a,b+1).second};
    else return {1+cost(max(a/2 ,b), min(a/2, b)).first, cost(max(a/2 ,b), min(a/2, b)).second};
}

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl a(n);
        input(a);
        //map<ll, ll> ml;
        unordered_map<ll, pair<ll,ll>> freq;
        ll ans=INT_MAX;

        loop(i,n){
            freq[a[i]].first++;
            ll cnt=0;
            freq[a[i]].second+=cnt;
            if(a[i]==1){
                freq[2].second++;
                freq[2].first++;
            }
            else{
                while(a[i]!=1){
                    cnt++;
                    if(a[i]%2) {
                        a[i]++;
                        freq[a[i]].first++;
                        freq[a[i]].second+=cnt;
                    }
                    else{
                        a[i]/=2;
                        freq[a[i]].first++;
                        freq[a[i]].second+=cnt;
                    }
                }
            }
        }
        
        for(auto x:freq){
            if(x.second.first==n) ans=min(ans, x.second.second);
            //cout<<x.first<<" "<<x.second<<endl;
            //cout<<ml.count(x.first)<<endl;
        }

        // vector<vector<pair<ll,ll>>> freq(n);
        // loop(i,n){
        //     ll cnt=0;
        //     freq[i].pb({a[i],cnt});
        //     if(a[i]==1) freq[i].pb({2,1});
        //     while(a[i]!=1){
        //         cnt++;
        //         if(a[i]%2) {
        //             a[i]++;
        //             freq[i].pb({a[i],cnt});
        //         }
        //         else{
        //             a[i]/=2;
        //             freq[i].pb({a[i],cnt});
        //         }
        //     }
        // }


        // // ll mini = INT_MAX;
        // // loop(i,n) mini=min(mini, a[i]);
        // ll ans=0, k;
        // for(ll i=1; i<n;i++){
        //     ans+=cost(max(a[i], a[i-1]), min(a[i],a[i-1])).first;
        //     a[i]=cost(max(a[i], a[i-1]), min(a[i],a[i-1])).second;
        // }
        cout<<ans<<endl;
       
        
    }
}
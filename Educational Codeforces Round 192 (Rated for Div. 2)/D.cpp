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
const ll MOD = 1e9+7;
// memset(a, -1, sizeof(a));

ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    fastio;
    test{
        string a,b;
        cin>>a>>b;
        ll n=a.size(),m=b.size(),ans=0;

        vl pa(n+1),pb(m+1);
        pa[1]=a[0]-'0'; pb[1]=b[0]-'0';
        for(ll i=2; i<=n; i++) pa[i]=(pa[i-1]+(a[i-1]-'0'))%10;
        for(ll i=2; i<=m; i++) pb[i]=(pb[i-1]+(b[i-1]-'0'))%10;
        if(pa[n]!=pb[m]) cout<<-1<<endl;
        else{
            
            for(ll s=1; s<=n; s++){
                ll idx1=0, idx2=0, k=0;
            for(ll i=s; i<=n; i++){
                for(ll j=idx2+1; j<=m; j++){
                    if(pa[i]-pa[idx1]==pb[j]-pb[idx2]){
                        idx2=j;
                        idx1=i;
                        k++;
                        break;
                    }
                }
                //cout<<k;
            }
        ans=max(ans,k);
    }
            cout<<ans<<endl;
        }
        
    //     loop(i,n){
    //         ll ans1=0;
    //         r=q; idx=-1; idx2=0;
    //         // q= (q+(a[i]-'0'))%10;
    //         for(ll j=i; j<n; j++){
    //             if(a[j]=='0' && idx==m-1){
    //             idx2=j;
    //             continue;
    //             }
    //             r=(r+(a[j]-'0'))%10;
    //             ll p=0;
    //             for(ll k=idx+1; k<m; k++){
    //             //     if(b[k]=='0' && idx2==n-1){
    //             //     idx=k;
    //             //     continue;
    //             // }
    //                 p= (p+(b[k]-'0'))%10;
    //                 if(r==p) {
    //                 idx=k;
    //                 // while(idx+1<m && b[idx+1]=='0') idx++;
    //                 idx2=j;
    //                 ans1++;
    //                 r=0;
    //                 if(idx2==n-1) {
    //                     while(idx+1<m && b[idx+1]=='0') idx++;
    //                 }
    //                 //cout<<i+1<<" "<<j+1<<endl;
    //                 break;
    //                 }
    //                 // if(k==m-1) f=1;
    //             }
    //             // if(f) break;
    //         }
    //         q= (q+(a[i]-'0'))%10;
    //         if(ans1!=0 && idx==m-1 && idx2==n-1) ans= max(ans,ans1);
    //     }


    // //         if(a[i]=='0'){
    // //             idx2=i;
    // //             continue;
    // //         }
    // //         ll k=0;
    // //         q= (q+a[i]-'0')%10;
    // //         for(ll j=idx+1; j<m; j++){
    // //             ll p=b[j]-'0';
    // //             k=(k+p)%10;
    // //             if(k==q) {
    // //                 idx=j;
    // //                 idx2=i;
    // //                 ans++;
    // //                 q=0;
    // //                 //cout<<i+1<<" "<<j+1<<endl;

    // //                 break;
    // //             }
    // //         }
    // //     }
    //     if(ans==0) cout<<-1<<endl;
    //     else cout<<ans<<endl;
    }
    
    return 0;
}
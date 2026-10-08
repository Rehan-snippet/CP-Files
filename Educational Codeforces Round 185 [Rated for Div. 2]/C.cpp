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
        ll n,k,ans=0, idx=0, idx2=0;
        cin>>n>>k;
        vl r(n), q(n);
        input(q); input(r);
        sort(all(q)); sort(allr(r));
        while(idx<n && idx2<n){
            if(k>= q[idx]*r[idx2] + q[idx] + r[idx2]) {
                ans++; idx++; idx2++;
            }
            else idx2++; 
        }

        // output(q); cout<<endl; 
        // output(r); cout<<endl;
        // for(ll i=n-1; i>=0; i--){
        //     if(k>= q[0]*r[i] + q[0] + r[i]) {
        //         idx=i; break;
        //     }
        // }
        // if(idx!=-1){
        // for(ll i=n-1; i>=0; i++){
        //     if(k>= q[i]*r[idx] + r[idx] + q[i]){
        //         idx2=i; ans= i+1; break;
        //     }
        // }
        // idx2++;
        // while(idx2<n){
        //     if(k>= r[idx3]*q[idx2] + r[idx3] + q[idx2]) ans++;
        //     else break;
        //     idx2++; idx3++;
        // }
        // }
        cout<<ans<<endl;

        

    }
    
    return 0;
}
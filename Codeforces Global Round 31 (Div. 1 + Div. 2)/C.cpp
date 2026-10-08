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
        ll n,k;
        cin>>n>>k;
        vl b;
        ll nn=n, idx=-1, exp=0, mul=1, size=0;
        if(k%2==0) {
            ll first=0, second=0;
            while(n){
                b.pb(n%2);
                size++;
                n/=2LL;
            }
            for(ll i=size-2; i>=0; i--){
                if(b[i]==1) {
                    idx=i;
                    break;
                }
            }
            // output(b); cout<<endl;
            // cout<<idx<<endl;
            if(idx!=-1){
                for(ll i=0; i<idx; i++){
                    if(b[i]==1){
                        exp=i; mul=1;
                        // for(ll j=1; j<=exp; j++){
                        //     mul*=2;
                        // }
                        mul = 1LL << exp;
                        first+=mul;
                    }
                    else{
                        exp=i; mul=1;
                        // for(ll j=1; j<=exp; j++){
                        //     mul*=2;
                        // }
                        mul = 1LL << exp;
                        first+=mul;
                        second+=mul;
                    }
                }

                    exp=idx; mul=1;
                        // for(ll j=1; j<=exp; j++){
                        //     mul*=2;
                        // }
                        mul = 1LL << exp;
                        second+=mul;

                for(ll i=idx+1; i<size; i++){
                    if(b[i]==1){
                        exp=i; mul=1;
                        // for(ll j=1; j<=exp; j++){
                        //     mul*=2;
                        // }
                        mul = 1LL << exp;
                        first+=mul;
                    }
                }
                if((first+second)>nn){
                    cout<<second<<" "<<first<<" ";
                    k-=2;
                }
                else{
                    cout<<0<<" "; 
                    k--;
                }
            }
            else{
                cout<<0<<" "; 
                k--;
            }
        }
            for(ll i=0; i<k; i++){
                cout<<nn<<" ";
            }
            cout<<endl;     
        
    }
    
    return 0;
}
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
#define MOD  676767677
// memset(a, -1, sizeof(a));

int main() {
    fastio;
    test{
        ll n,k;
        cin>>n>>k;
        vl a(n), b(n);
        input(a); input(b);

        // vl fa(n+1), fb(n+1);
        // loop(i,k){
        //     fa[a[i]]++;
        //     if(b[i]!=-1) fb[b[i]]++;
        // }

        int f=0;
        // ll imp= n-k;

        // loop(i,k){
        //     if(fb[b[i]]>fa[b[i]]){
        //         f=1;
        //         break;
        //     }
        // }

            loop(i,k){
                if(b[i]==a[i]) {
                    ll j=i+k;
                    while(j<n){
                        if(b[j]!=-1 && b[j]!=a[j]){
                            f=1;
                            break;
                        }
                        j+=k;
                    }
                }
                else if(b[i]==-1){
                    ll j=i+k, val=0;
                    while(j<n){
                        if(b[j]!=-1){
                            if(b[j]==a[j]){
                                b[i]=a[i];
                                i--;
                                break;
                            }
                            else{
                                b[i]= b[j];
                                i--;
                                break;
                            }
                        }
                        j+=k;
                    }
                }

                else if(b[i]!=a[i]){
                    ll j=k+i;
                    while(j<n){
                        if(b[j]==-1) b[j]=b[i];
                        if(b[j]!=b[i] || a[j]!=a[i]) {
                            f=1;
                            break;
                        }
                        j+=k;
                    }
                }

                if(f) break;
            }


        if(f) no;
        else yes;

        
    }
    
    return 0;
}
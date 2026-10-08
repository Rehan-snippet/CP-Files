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
        ll n, m, h;
        cin>>n>>m>>h;
        vl a(n), org(n);
        input(a);
        loop(i,n){
            org[i]=a[i];
        }

        vl b(m),c(m);
        loop(i,m){
            cin>>b[i]>>c[i];
        }

        ll lastCrash=-1;
        vl lastChange(n,-1);

        loop(i,m){
            if(lastChange[b[i]-1]>lastCrash) a[b[i]-1]+=c[i];
            else a[b[i]-1]=c[i]+org[b[i]-1];

            if(a[b[i]-1]>h){
                lastCrash=i;
                lastChange[b[i]-1]=-1;
            }
            else{
                lastChange[b[i]-1]=i;
            }

        }
        for(ll i=lastCrash+1; i<m; i++){
            org[b[i]-1]+= c[i];
        }
        output(org);
        cout<<endl;
        

    }
    
    return 0;
}
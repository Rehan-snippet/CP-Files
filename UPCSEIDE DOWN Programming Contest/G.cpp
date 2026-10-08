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
    int n;
    cin>>n;
    vector<vector<ll>> p(n), q(n);
    ll x;
    loop(i,n){
            loop(j,n){
            cin>>x;
            p[i].pb(x);
        }   
    }

    loop(i,n){
        loop(j,n){
            q[i].pb(p[i][j]);
        }
    }

    loop(i,n){
        loop(j,n){
            if(i>0) q[i][j]-=p[i-1][j];
            if(j>0) q[i][j]-=p[i][j-1];
            if(i>0 && j>0) q[i][j]+=p[i-1][j-1];
        }
    }
    ll sum=0;
    loop(i,n){
        sum+=q[i][i];
    }
    q[0][0]-=sum;

    loop(i,n){
        loop(j,n){
            cout<<q[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
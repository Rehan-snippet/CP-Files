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
        vl a(n);
        input(a);
        ll mex=0;
        sort(all(a));
        loop(i,n){
            if(a[i]==mex) mex++;
            else if(a[i]>mex) break;
        }
        ll zero=0;
        loop(i,n){
            if(a[i]>0) break;
            zero++;
        }

        if(mex>1) yes;
        else if(mex==1 && zero==1) yes;
        else no;
        // cout<<mex<<endl;

    }
    
    return 0;
}
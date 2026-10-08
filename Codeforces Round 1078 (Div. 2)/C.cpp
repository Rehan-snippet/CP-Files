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

int main() {
    fastio;
    test{
        ll n,k, count;
        cin>>n>>k;
        char ch; bool f=0;
        vector<set<char>> sch(n);
        string ans, dummy;
        loop(i,k){
            loop(j,n){
                cin>>ch;
                if(i==0) dummy.pb(ch);
                sch[j].insert(ch);
            }
        }

        loop2(i,n){ 
            if(n%i==0){
                count=n/i;
                loop(j,i){
                    for(auto x:sch[j]){
                        ans.pb(x);
                        for(ll p=j; p<n; p+=i){
                            if(sch[p].find(x)==sch[p].end()){
                                ans.pop_back();
                                break;
                            }
                        }
                        if(ans.size()==j+1 && ans[ans.size()-1]==x) break;
                    }
                    if(ans.size()!=j+1) {
                        ans.clear();
                        break;
                    }
                }
                if(ans.size()==i) {
                    f=1;
                    break;
                }
            }
        }

        if(f){
            loop(i,count) cout<<ans;
            cout<<endl;
        }
        else cout<<dummy<<endl;
        
    }    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
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
        ll n, m, k;
        cin>>n>>m>>k;
        vl a(n), b(m);
        vector<pair<ll,ll>> dis(n);
        input(a); input(b);
        string s;
        cin>>s;
        sort(all(a)); sort(all(b));

        ll spike=0;
        loop(i,n){
            auto it= upper_bound(all(b), a[i]);
            ll idx= it-b.begin();

            if(idx==0) {
                dis[i].first=-1;
                dis[i].second=b[idx]-a[i];
            }
            else if(idx==m){
                dis[i].first= a[i]-b[idx-1];
                dis[i].second=-1;
            }
            else {
                dis[i].second=b[idx]-a[i];
                dis[i].first= a[i]- b[idx-1];
            }
        }

        vl dead(k,0), left(k+1,-1), right(k+1, -1);
        ll x=0;
        loop(i,k){
            if(s[i]=='L'){
                x--;
                if(x<0 && left[-x]==-1) left[-x]=i;
            }
            else{
                x++;
                if(x>0 && right[x]==-1) right[x]=i;
            }
        }

        loop(i,n){
            //cout<<"uihui\n";
            if(dis[i].first!=-1 && dis[i].first<=k && left[dis[i].first]!=-1 ){
                if(dis[i].second!=-1 && dis[i].second<=k && right[dis[i].second]!=-1){
                    dead[min(left[dis[i].first],right[dis[i].second])]++;
                }
                else dead[left[dis[i].first]]++;
                //cout<<left[dis[i].first]<<endl;
            }

            else if(dis[i].second!=-1 && dis[i].second<=k && right[dis[i].second]!=-1){
                dead[right[dis[i].second]]++;
                //cout<<right[dis[i].second]<<endl;
            }
        }

        // loop(i,n){
        //     cout<<dis[i].first<<" "<<dis[i].second<<endl;
        // }
        loop(i,k){
            n-=dead[i];
            cout<<n<<" ";
        }
        // output(dead);
        cout<<endl;


        // output(left);
        // cout<<endl;
        // output(right);
        // cout<<endl;
        // cout<<endl;
        

    }
    
    return 0;
}
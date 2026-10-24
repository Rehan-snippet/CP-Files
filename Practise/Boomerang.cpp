#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class Graph
{
public:
    ll n;
    vector<vector<ll>> adj;
    vector<ll> visited, dist, parent;
    vector<tuple<ll,ll,ll>> ans;
    map<pair<ll, ll>, ll> mp;

    Graph(ll n)
    {
        this->n = n;
        adj.resize(n + 1);
        visited.assign(n + 1, 0);
        dist.assign(n + 1, -1);
        parent.assign(n + 1, -1);
    }

    void addEdge(ll u, ll v, bool undirected = true)
    {
        adj[u].pb(v);

        if (undirected)
        {
            adj[v].pb(u);
        }
    }


    void helper( ll idx) {

    stack<ll> st;
    st.push(idx);
    parent[idx]=-1;
    
    while (!st.empty()) {
        ll node = st.top();
        
        if (visited[node] == true) {
            //cout<<node<<" ";
            ll size = adj[node].size();
            for(ll i=size-1; i>0; i--){
                for(ll j=i-1; j>=0; j--){
                    pair<ll,ll> p1= {node, adj[node][i]};
                    pair<ll,ll> p2= {node, adj[node][j]};
                    pair<ll,ll> p3= {adj[node][i], node};
                    pair<ll,ll> p4= {adj[node][j], node};
                    if(!mp[p1] && !mp[p2] && !mp[p3] && !mp[p4]){
                        ans.push_back({p1.second, node, p2.second});
                        mp[p1]=1; mp[p2]=1; mp[p3]=1; mp[p4]=1;
                        break;
                    } 
                }
                
            }
            st.pop();
            continue;
        }

        visited[node] = true;
        //res.push_back(node);
        
        ll size = adj[node].size();
        for (ll i=size-1; i>=0; i--) {
            ll v = adj[node][i];
            if (!visited[v]) {
                parent[v]=node;
                st.push(v);
            }
        }
    }
    
}

    void solve(){
        for(ll i=1; i<=n; i++){
            if(!visited[i]) helper(i);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin>>n>>m;
    ll edg=m;
    Graph g(n);

    while(m--){
        ll u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.solve();

    cout<<g.ans.size()<<endl;
    for(ll i=0; i<g.ans.size(); i++){
        cout<<get<0>(g.ans[i])<<" "<<get<1>(g.ans[i])<<" "<<get<2>(g.ans[i])<<endl;
    }

    return 0;
}

// ID:1792003861458
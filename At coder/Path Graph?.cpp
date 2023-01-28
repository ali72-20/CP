// author: Ali Safwat
#include <bits/extc++.h>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Caraxes  ios_base :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long int
#define F first
#define S second
using namespace std;
// using namespace __gnu_pbds;

template< typename  T = int >
std :: vector < T > get(int size = 0, std :: istream& in_stream = std :: cin);

const int N = 2e5 + 20;
vector <int>g[N];
struct DSU{
    int par[N],sz[N];
    void init(int n){
        for(int i = 0;i <= n; ++i)
            par[i] = i, sz[i] = 1;
    }
    int find_par(int u){
        return par[u] == u ? u : find_par(par[u]);
    }
    void connect(int u, int v){
        u = find_par(u);
        v = find_par(v);
        if(v == u)
            return;
        if(sz[v] < sz[u])
            swap(u,v);
        par[u] = v;
        sz[v]+=sz[u];
    }

    bool same(int u, int v){
        u = find_par(u);
        v = find_par(v);
        return u == v;
    }

}dsu;
void Dracarys(){
    int n,m;
    cin >> n >> m;
    dsu.init(n);
    for(int i = 0;i < m; ++i){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        dsu.connect(u,v);
    }
    if(m != n - 1)
        return cout << "No\n",void();
    for(int i = 1;i <= n; ++i){
        if(g[i].size() > 2)
            return cout << "No\n",void();
    }
    for(int i = 2; i <= n; ++i){
        if(!dsu.same(1,i))
            return cout << "No\n",void();
    }
    cout << "Yes\n";
}


signed main()
{
    Caraxes
    int test = 1;
   // cin >> test;
    while(test--) {
        Dracarys();
    }
}

template< typename  T>
std :: vector < T > get(int size , std :: istream& in_stream){
    if(!size){
        in_stream >> size;
    }
    std :: vector < T > array(size);
    for(auto& i : array)
        in_stream >> i;
    return array;
}

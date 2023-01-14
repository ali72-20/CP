// author: Ali Safwat
#include <bits/extc++.h>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Caraxes  ios_base :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long int
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
const int N = 2e5 + 20;
vector < int > g[N];
int deg[N];
string ans;
bool valid;
void DFS(int node, int d){
    deg[node] = d;
    for(auto ch : g[node]){
        if(~deg[ch]){
            if(deg[ch] == d) {
                valid = false;
                return ;
            }
            continue;
        }
        DFS(ch, d ^ 1);
    }
}
void Dracarys() {
    memset(deg,-1,sizeof deg);
    int n,m;
    cin >> n >> m;
    vector <pair<int,int>> edges;
    for(int i = 0;i < m; ++i){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.emplace_back(u,v);
    }
    valid = true;
    DFS(1,0);
    if(valid){
        cout << "YES\n";
        for(auto[f,s] : edges)
            cout << (deg[f] < deg[s]);
    }
    else cout << "NO\n";
}
signed main()
{
    Caraxes
    int test = 1;
    //cin >> test;
    while(test--) {
        Dracarys();
    }
}
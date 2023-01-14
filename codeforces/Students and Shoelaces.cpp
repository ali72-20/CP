// author: Ali Safwat
#include <bits/extc++.h>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Caraxes  ios_base :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long int
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;

template< typename  T = int >
std :: vector < T > get(int size = 0, std :: istream& in_stream = std :: cin);
vector < int > g[105];
void Dracarys() {
    int n,m;
    cin >> n >> m;
    map < int, int > mp;
    for(int i = 0;i < m; ++i){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[u]++;
        mp[v]++;
    }
    int ans = 0;
    while(true){
        bool f = true;
        vector < int > rem;
        for( int i = 1; i <= n; ++i){
            if(mp[i] == 1){
                mp[i] = 0;
                f = false;
                for(auto ch : g[i])
                    rem.push_back(ch);
            }
        }
        if(!f) ans++;
        for(auto it : rem)
            mp[it]--;
        if(f){
            cout << ans;
            exit(0);
        }
    }
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
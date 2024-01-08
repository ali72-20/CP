#pragma GCC optimize("Ofast")

#include <bits/extc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
typedef long long int ll;

void Clion(){
#ifndef ONLINE_JUDGE
    ::freopen("in.txt","r",stdin);
    ::freopen("out.txt","w",stdout);
#endif
}

const double EPS = 1e-9;
const ll OO = 0X3F3F3F3F3F3F3F3F;
const int N = 2e5 + 5, INF = INT_MAX, MOD = 1e9 + 7, LOG = 20;
vector<int> G[N];

struct LCA
{
    vector<int> lvl;
    vector<vector<int>> up;

    LCA(int n)
    {
        lvl = vector<int>(n + 1, 0);
        up = vector<vector<int>>(n + 1, vector<int>(LOG));
        dfs(1, -1);
    }

    void dfs(int node, int par)
    {
        for(int i = 1; i < LOG; i++)
            up[node][i] = up[up[node][i - 1]][i - 1];

        for(auto ch: G[node])
        {
            if(ch == par)
                continue;

            up[ch][0] = node;
            lvl[ch] = lvl[node] + 1;

            dfs(ch, node);
        }
    }

    int getKthParent(int node, int k)
    {
        for(int i = LOG - 1; i >= 0; i--)
        {
            if((k >> i) & 1) {
                node = up[node][i];
            }
        }
        return node;
    }

    int lca(int a, int b)
    {
        if(lvl[a] < lvl[b])
            swap(a, b);

        a = getKthParent(a, lvl[a] - lvl[b]);

        if(a == b)
            return a;

        for(int i = LOG - 1; i >= 0; i--)
        {
            if(up[a][i] != up[b][i])
                a = up[a][i], b = up[b][i];
        }

        return up[a][0];
    }

    int dist(int a, int b)
    {
        int l = lca(a, b);
        return (lvl[a] - lvl[l]) + (lvl[b] - lvl[l]);
    }
};
int par[N];
void bfs(int node){
    queue<int> q;
    q.emplace(node);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto ch : G[cur]){
            if(par[ch] == -1 && ch != 1){
                par[ch] = cur;
                q.push(ch);
            }
        }
    }
}
void run() {
  int n,q;
  cin >> n >> q;
  int id = 2;
  map<char,int> hash1;
  map<int,char> hash2;
  hash1['R'] = 1;
  hash2[1] = 'R';
  for(int i = 0;i < n; ++i){
      string s,t;
      cin >> s >> t;
      int u,v;
      if(hash1.find(s.front()) == hash1.end()) {
          u = id++;
          hash1[s.front()] = u;
          hash2[u] = s.front();
      }
      else
          u = hash1[s.front()];
      if(hash1.find(t.front()) == hash1.end()){
          v = id++;
          hash1[t.front()] = v;
          hash2[v] = t.front();
      }else{
          v = hash1[t.front()];
      }
      G[u].emplace_back(v);
      G[v].emplace_back(u);
  }
    memset(par,-1,sizeof par);
  bfs(1);

  LCA lca(id);
  while(q--){
      string s,t;
      cin >> s >> t;
      auto ret = lca.lca(hash1[s.front()],hash1[t.front()]);
      string a1,a2;
      auto st = hash1[s.front()];
      while(st != ret){
          a1.push_back(hash2[st]);
          st = par[st];
      }
      a1.push_back(hash2[ret]);
       st = hash1[t.front()];
      while(st != ret){
          a2.push_back(hash2[st]);
          st = par[st];
      }
      reverse(a2.begin(),a2.end());
      cout << a1 << a2 <<  '\n';
  }
    for(int i = 0;i <= id; ++i)
        G[i].clear();
}

signed main() {
    FIO
    Clion();
    int TestC = 1;
    cin >> TestC;
    while(TestC--){
        run();
        if(TestC)
            cout << '\n';
    }
    return 0;
}

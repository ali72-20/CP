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
map <int, int > dist;
int inf = 1e9;
void Dracarys(){
    // hint: s < 1e9 ? s = 1e9
    // note: l <= r

    int n,k,s;
    cin >> n >> k >> s;
    vector < int > ans;
    while(k--){
        ans.push_back(s);
        n--;
    }
    if(s < inf)for(int i = 0;i < n; ++i) ans.push_back(s + 1);
    else for(int i = 0;i < n; ++i) ans.push_back(1);
    for(auto it : ans)
        cout << it << ' ';
    exit(0);
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
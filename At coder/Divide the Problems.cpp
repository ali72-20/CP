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
void Dracarys() {
    int n;
    cin >> n;
    auto v = get(n);
    sort(v.begin(),v.end());
    int a1 = v[n / 2];
    int a2 = v[n / 2 - 1];
    cout << abs(a1 - a2) << '\n';
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
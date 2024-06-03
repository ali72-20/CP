#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"


using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
typedef long long int ll;

const double EPS = 1e-9;
const ll OO = 0X3F3F3F3F3F3F3F3F;
const int N = 1e5 + 5, INF = INT_MAX, mod = 1e9 + 7, p = 31, LOG = 20;
vector<pair<int,int>> vp;
int dp[N];
int n;
int cunstom_lower(int val){
    int l = 0,r = n - 1,mid,ans = n;
    while(l <= r){
        mid = (l + r) >> 1;
        if(vp[mid].first >= val){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}
int solve(int i){
    if(i >= n) return 0;
    if(~dp[i])
        return dp[i];
    auto nxt = cunstom_lower(vp[i].second);
    dp[i] = 1;
    if(nxt != n){
        dp[i] = 1 + solve(nxt);
    }
    dp[i] = max(dp[i],solve(i + 1));
    return dp[i];
}
void run() {

    cin >> n;
    vp.resize(n);
    for(int i = 0;i < n; ++i){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(),vp.end());
    memset(dp,-1,sizeof dp);
    auto ans = solve(0);
    cout << ans << '\n';

}

signed main() {
    FIO
    int TestC = 1;
    cin >> TestC;
    while(TestC--){
        run();
    }
    return 0;
}




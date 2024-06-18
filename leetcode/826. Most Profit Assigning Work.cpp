class Solution {
public:
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    vector<pair<int,int>> vp;
    int n = (int)profit.size();
    for(int i = 0;i < n; ++i){
        vp.push_back({profit[i], difficulty[i]});
    }
    sort(vp.rbegin(), vp.rend());
    sort(worker.begin(),worker.end());
    int ans = 0;
    int limit =(int) worker.size();
    for(int i = 0;i < n; ++i){
        auto pos = lower_bound(worker.begin(), worker.begin()+ limit,vp[i].second);
        if(pos != worker.end()){
            int num = pos - worker.begin();
            ans += (vp[i].first) * (limit - num);
            limit = num;
        }
    }
    return ans;
}
};

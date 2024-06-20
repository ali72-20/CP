class Solution {
public:
   bool valid(vector<int>& pos, int mid, int m){
      int prev = pos.front(); 
      for(int i = 1; i < m; ++i){
        auto nxt = lower_bound(pos.begin(), pos.end(), prev + mid);
        if(nxt == pos.end()){
            return false;
        }
        prev = *nxt;
      }
      return true;
   }
   
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l =0, r = position.back(),ans = 1, mid;
        while(l <= r){
            mid = (l + r) >> 1;
            if(valid(position,mid,m)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};

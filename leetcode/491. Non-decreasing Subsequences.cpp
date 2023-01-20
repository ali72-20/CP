class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector < vector < int >> ans;
        int n = (int)nums.size();
        map < vector < int >, bool > mp;
        for(int msk = 0; msk < (1LL << n); ++msk){
            if(__builtin_popcount(msk) < 2) 
                continue;
            vector < int > tmp;
            for (int i = 0;i < n; ++i){
                if(msk & (1LL << i)){
                    tmp.push_back(nums[i]);
                }
            }
            if(mp.find(tmp) == mp.end()){// if not found
                 if(is_sorted(tmp.begin(),tmp.end())){
                     ans.push_back(tmp);
                 }
                 mp[tmp] = true;
            } 
        }
        return ans;
    }
};


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        if(points.size() < 2) return points.size();
        ans = 2;
        int n = points.size();
        set<pair<int, int>> filter;
        unordered_map<double, int> hash;
        for(int i=0; i<n; i++)
        {
            int same_x = 1, same_point = 1;
            for(int j=i+1; j<n; j++)
            {
                double rate = 1.0*(points[j][1] - points[i][1])/(points[j][0] - points[i][0]);
                bool same_xasic = (points[j][0] == points[i][0]);
                if(same_xasic){
                    ++same_x;
                    if(points[j][1] == points[i][1])
                        same_point++;
                }
                ++hash[rate];
            }
            ans = max(ans, same_x);
            for(auto x:hash)
            {
                ans = max(ans, same_point + x.second);
            }
            hash.clear();
        }
        return ans;

    }
};
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        if(points.size() < 2) return points.size();
        ans = 2;
        int n = points.size();
        set<pair<int, int>> filter;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double rate = 1.0*(points[j][1] - points[i][1])/(points[j][0] - points[i][0]);
                bool same_xasic = (points[j][0] == points[i][0]);
                int temp = 2;
                vector<int> same_point;
                if(filter.count(make_pair(i, j))) continue;
                for(int w=j+1; w<n; w++)
                {
                    double temprate = 1.0*(points[w][1] - points[i][1])/(points[w][0] - points[i][0]);
                    if(temp + (n-w) <= ans) break;
                    if(same_xasic)
                    {
                        if(points[w][0] == points[i][0]){
                            ++temp;
                        
                            for(auto x:same_point)
                            {
                                filter.insert(make_pair(x, w));
                            }
                            same_point.push_back(w);
                        }

                    }
                    else if(temprate == rate)
                    {
                        ++temp;
                        for(auto x:same_point)
                        {
                            filter.insert(make_pair(x, w));
                        }
                         same_point.push_back(w);
                    }

                } 
                ans = max(ans, temp);

            }
        }
        return ans;

    }
};
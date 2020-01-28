class Solution {
public:
    int cal_gcd(int x, int y)
    {
        if(x ==0)
            return y;
        return cal_gcd(y%x, x);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<= 2)
            return points.size();
        
        int cur_max, similar, infinity, x, y, maxx=0, g;
        map<pair<int, int>, int> status;
        map<pair<int, int>, int> :: iterator itr;
        
        for(int i=0; i< points.size(); i++)
        {
            cur_max=0;
            similar= 0;
            infinity= 0;
            
            for(int j= i+1; j < points.size(); j++)
            {
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    similar++;
                
                else if(points[i][0] == points[j][0])
                    infinity++;
                
                else
                {
                    x= points[i][0]- points[j][0];
                    y= points[i][1]- points[j][1];
                    
                    g= cal_gcd(x, y);
                    
                    x /= g;
                    y /= g;
                    
                    itr= status.find(make_pair(x, y));
                    if(itr == status.end())
                        status.insert({make_pair(x, y), 1});
                    else
                        itr->second +=1;
                    
                    itr= status.find(make_pair(x, y));
                    cur_max= max(cur_max, itr->second);
                }
                cur_max= max(cur_max, infinity);
            }
            maxx =max(cur_max+ similar+1, maxx);
            status.clear();
        }
        
        return maxx;
    }
};
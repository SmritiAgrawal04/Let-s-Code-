class UndergroundSystem {
public:
    map<int, pair<string, int>> start;
    map<pair<string, string>, pair<int, int>> status;
    map<pair<string, string>, pair<int, int>> :: iterator itr;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        if (start.find(id) != start.end())
            return;
        start[id]= make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        pair<string, int> p;
        p= start.find(id)-> second;
        itr= status.find(make_pair(p.first, stationName)) ;
        if (itr == status.end())
            status[make_pair(p.first, stationName)] = make_pair(t- p.second, 1);
        
        else
        {
            int current= itr->second.first +t- p.second;
            int count= itr->second.second +1;
            status[make_pair(p.first, stationName)] = make_pair(current, count);
        }
         
        start.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        pair<int, int> p= status.find(make_pair(startStation, endStation))->second;
        return double(p.first)/double(p.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
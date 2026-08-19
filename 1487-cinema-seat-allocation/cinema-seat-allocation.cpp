class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedseats) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto &reservedseat:reservedseats)
        {
            int row=reservedseat[0];
            int seat=reservedseat[1];
            mp[row].insert(seat);
        }
        int result=(n-mp.size())*2;
        for(auto &[row,bookedseat]:mp)
        {
            auto isavailable=[&](int seat){
                return bookedseat.find(seat)==bookedseat.end();
            };
            bool groupA=isavailable(2) && isavailable(3) && isavailable(4) && isavailable(5); 
            bool groupB=isavailable(4) && isavailable(5) && isavailable(6) && isavailable(7); 
            bool groupC=isavailable(6) && isavailable(7) && isavailable(8) && isavailable(9); 
            if(groupA && groupC)
            {
                result+=2;
            }
            else if( groupA || groupB || groupC)
            {
                result+=1;
            }
        }
        return result;
    }
};
class Solution {
public:
    
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        
        result.push_back(label);
        int row= floor(log2(label));
        int pos;
        
        while(row> 0)
        {
            if(row%2)
                pos= (2*pow(2,row)) - label-1;
            else
                pos= label- pow(2, row);
            
            pos /=2;
            row--;
            
            if(row%2)
                label= (2*pow(2,row)) - pos-1;
            else
                label= pow(2, row) +pos;
            
            result.push_back(label);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
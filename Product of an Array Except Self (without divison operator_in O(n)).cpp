class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int left[nums.size()];
        left[0]= 1;
        int right[nums.size()];
        right[nums.size()-1]= 1;
        
        for(int i= 1; i< nums.size(); ++i)
            left[i]= left[i-1] * nums[i-1];
        
        for(int i= nums.size()-2; i>-1; i--)
            right[i]= right[i+1] * nums[i+1];
        
        for(int i=0; i< nums.size(); i++)
            result.push_back(left[i] * right[i]);
        
        return result;
    }
};
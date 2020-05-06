/*Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i=0 ;i< nums.size(); i++)
        {
            int x= abs(nums[i]) -1;
            if(nums[x] < 0)
                result.push_back(x+1);
            else
                nums[x] = 0 -nums[x];
        }
        return result;
    }
};
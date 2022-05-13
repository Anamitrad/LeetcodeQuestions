class Solution {
public:
    void permuteHelper(int maxSize,vector<int>temp,map<int,int> freq,vector<vector<int>> &ans){
        if(temp.size()==maxSize)
        {
            ans.push_back(temp);
            return;
        }
        for(map<int,int>::iterator it=freq.begin();it!=freq.end();it++)
        {
            if(it->second!=0)
            {
                temp.push_back(it->first);
                it->second--;
                permuteHelper(maxSize,temp,freq,ans);
                temp.pop_back();
                it->second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        permuteHelper(nums.size(),temp,freq,ans);
        return ans;
    }
};
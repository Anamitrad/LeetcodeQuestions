class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stck;

        for(int i=0;i<s.length();i++)
        {
            if(stck.empty())
            {
                stck.push({s[i],1});
                continue;
            }
            if(s[i]==stck.top().first)
            {
                if(stck.top().second==(k-1))
                {
                    while(!stck.empty() && stck.top().first==s[i])
                    {
                        stck.pop();
                    }
                }
                else
                {
                    int freq=stck.top().second;
                    stck.push({s[i],freq+1});
                }
            }
            else
            {
               stck.push({s[i],1}); 
            }
            
        }
        string ans="";
        while(!stck.empty())
        {
            ans+=stck.top().first;
            stck.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
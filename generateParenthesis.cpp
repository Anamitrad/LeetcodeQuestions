class Solution {
public:
    string addParenthesis(string s,int pos)
    {
        if(pos==0)
        {
            return s+ "()";
        }
        queue<char> q;
        int cnt=0;
        int i=0;
        while(cnt < pos)
        {
            q.push(s[i]);
            if(s[i]=='(')
            {
                cnt++;
            }
            i++;
        }
        q.push('(');
        q.push(')');
        while(i<s.length())
        {
            q.push(s[i]);
            i++;
        }
        string ans="";
        while(!q.empty())
        {
            ans+=q.front();
            q.pop();
        }
        return ans;
    }
    
    vector<string> generateHelper(vector<string> temp,int n){
        if(n==1)
        {
            temp.push_back("()");
            return temp;
        }
        unordered_set<string> unique;
        temp=generateHelper(temp,n-1);
       for(int i=0;i<temp.size();i++)
       {
          
           for(int j=0;j<n;j++)
           {
              unique.insert(addParenthesis(temp[i],j));
           }
       }
        vector<string>ans;
        for(auto it=unique.begin();it!=unique.end();it++)
        {
           ans.push_back(*it); 
        }
        return ans;
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        ans=generateHelper(ans,n);
        return ans;
    }
};
class Solution {
public:
    
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        int ans=0;
        int i=0;
        while(i<tasks.size())
        {
            int n=upper_bound(tasks.begin(),tasks.end(),tasks[i])-tasks.begin()-1;
            int tasks=(n-i+1);
           
            if(tasks == 1)
            {
                return -1;
            }
            if(tasks%3==0)
            {
                ans+=tasks/3;
            }
            else if(tasks%3==1)
            {
                ans+=2;
                tasks-=4;
                ans+=tasks/3;
            }
            else
            {
                ans++;
                tasks-=2;
                ans+=tasks/3;
            }
            i=n+1;
        }
        return ans;
    }
};
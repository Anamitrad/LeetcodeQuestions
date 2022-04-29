class Solution {
public:
    bool dfs(vector<int>&visited,vector<vector<int>>& graph,int a,int curr)
    {
        visited[curr]=a;
        bool check=true;
        for(int i=0;i<graph[curr].size();i++)
        {
            if(visited[graph[curr][i]]== 0)
            {
                check =dfs(visited,graph,a*(-1),graph[curr][i]);
                if(!check)
                {
                    return check;
                }
            }
            if(visited[graph[curr][i]]== a)
            {
                return !check;
            }
        }
        return check;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited;
        for(int i=0;i<graph.size();i++)
        {
            visited.push_back(0);
        }
        bool check=true;
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==0)
            {
                check=dfs(visited,graph,1,i);
                if(!check)
                {
                    return check;
                }
            }
        }
        return check;
    }
};
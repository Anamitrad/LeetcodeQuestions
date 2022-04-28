class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b)
    {
        return a[0]<b[0];
    }

    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(rectangles.begin(),rectangles.end(),cmp);
        vector<int> ans;
        unordered_map<int,vector<int>> htol;
        for(int i=0;i<rectangles.size();i++)
        {
         
         htol[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        
        for(int i=0;i<points.size();i++)
        {
            int temp=0;
            int j=points[i][1];
            
            while(j<=100)
            {
                if(htol.count(j)==0)
                {
                    j++;
                    continue;
                }
                int n=lower_bound(htol[j].begin(),htol[j].end(),points[i][0]) -htol[j].begin();
                temp+=htol[j].size()-n;
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
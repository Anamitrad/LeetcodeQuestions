#include <bits/stdc++.h>
using namespace std;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string>::iterator it;
        bool isPresent=false;
        for(it= wordList.begin();it!= wordList.end();it++)
        {
            if(endWord == *it)
            {
                isPresent=true;
            }
        }
        if(!isPresent)
        {
            return 0;
        }
        unordered_set<string> list;
        for(it= wordList.begin();it!= wordList.end();it++)
        {
            list.insert(*it);
        }
        queue<string> bfs;
        bfs.push(beginWord);
        list.erase(beginWord);
        int depth=0;
        while(!bfs.empty())
        {
            int size=bfs.size();
            depth++;
            while(size>0)
            {
                string word=bfs.front();
                bfs.pop();
                for(int i=0;i<word.length();i++)
                {
                    string temp=word;
                    for(char c='a';c<='z';c++)
                    {
                        temp[i]=c;
                        
                        if(list.find(temp)!=list.end())
                        {
                            list.erase(temp);
                            if(temp == endWord)
                            {
                                return depth+1;
                            }
                            bfs.push(temp);
                        }
                        temp=word;
                    }
                    
                }
                
                size--;
            }
        }
        return 0;
    }

#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    int size=0;
    int cap;
    unordered_map<int,list<pair<int,int>>:: iterator> umap;
    list<pair<int,int>>nums;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(umap.count(key)==0)
        {
            return -1;
        }
        list<pair<int,int>>:: iterator i=umap[key];
        umap.erase(key);
        pair<int,int>temp =*i;
        nums.erase(i);
        nums.push_front(temp);
        umap[key]=nums.begin();
        return temp.second;
    }
    
    void put(int key, int value) {
        pair<int,int> temp=make_pair(key,value);
        int flag=0;
        if(umap.count(key)==0)
        {
            nums.push_front(temp);
            umap[key]=nums.begin();
             if(size<cap)
            {
                size++;
            }
            else
            {
                pair<int,int>temp1=*(nums.rbegin());
                nums.pop_back();
                int remKey=temp1.first;
                umap.erase(remKey);
            }
        }
        else
        {
            list<pair<int,int>>:: iterator i=umap[key];
            umap.erase(key);
            nums.erase(i);
            nums.push_front(temp);
            umap[key]=nums.begin();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
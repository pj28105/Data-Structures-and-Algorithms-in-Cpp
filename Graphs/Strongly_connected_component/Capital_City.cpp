#include<bits/stdc++.h>
using namespace std;

#define ERR
#ifdef ERR
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define deb(...)
#endif

void dfs1(int s,vector<int>g[],stack<int>&st,vector<bool>&vis){
    vis[s] = 1;
    for(int v : g[s]){
        if(!vis[v]){
            dfs1(v,g,st,vis);
        }
    }
    st.push(s);
}

void dfs2(int s,vector<int>tg[],vector<bool>&vis,unordered_map<int,int>&ma,int compId){
    vis[s] = 1;
    ma[s] = compId;
    for(int v : tg[s]){
        if(!vis[v]){
            dfs2(v,tg,vis,ma,compId);
        }
    }
    return;
}

int main(void){
    freopen("in.txt","r",stdin);
    int v,e;
    cin >> v >> e;
    vector<int>g[v],tg[v];
    for(int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        tg[b].push_back(a);
    }
    vector<bool>vis(v);
    stack<int> st;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs1(i,g,st,vis);
        }
    }
    fill(vis.begin(),vis.end(),0);
    int compId = -1;
    unordered_map<int,int> ma;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!vis[curr]){
            compId++;
            dfs2(curr,tg,vis,ma,compId);
        }
    }

    // Count Indgree of components through transpose graph
    vector<int>indeg(compId + 1);
    for(int i = 0; i < v; i++){
        for(int j : tg[i]){
            // Belongs To different components then increment indegree
            if(ma[j] != ma[i]){
                indeg[ma[j]]++;
            }
        }
    }
    // Count for components indegree zero
    int cou = 0,compNo = -1;
    for(int i = 0; i < (int)indeg.size(); i++){
        if(indeg[i] == 0){
            compNo = i;
            cou++;
        }
    }
    // If there are more components with indeg zero then capital city can't exists
    if(cou > 1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans;
    for(int i = 0; i < v; i++){
        if(ma[i] == compNo){
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
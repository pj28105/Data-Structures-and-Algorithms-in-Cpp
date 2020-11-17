#include <bits/stdc++.h>
using namespace std;

string printOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = printOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}

void dfs(char curr,unordered_set<char>&vis,unordered_map<char,unordered_set<char>>&g,string& ans){
    vis.insert(curr);
    for(char c : g[curr]){
        if(vis.find(c) == vis.end()){
            dfs(c,vis,g,ans);
        }
    }
    ans = curr + ans; 
}

string printOrder(string dict[], int n, int k) {
    unordered_map<char,unordered_set<char>>g;
    for(int i = 0; i < n; i++){
        bool found = 0;
        for(int j = i + 1; j < n; j++){
            int minlen = min(dict[i].length(),dict[j].length());
            for(int kl = 0; kl < minlen; kl++){
                if(dict[i][kl] != dict[j][kl]){
                    found = 1;
                    g[dict[i][kl]].insert(dict[j][kl]);
                    break;
                }
            }
            if(found)
                break;
        }
    }
    string ans = "";
    unordered_set<char>vis;
    for(int i = 0; i < 26; i++){
        if(vis.find('a' + i) == vis.end() && g.find(i + 'a') != g.end()){
            dfs('a' + i,vis,g,ans);
        }
    }
    return ans;
}
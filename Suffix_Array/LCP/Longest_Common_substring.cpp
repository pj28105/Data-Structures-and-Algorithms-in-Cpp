#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits.h>
#include <math.h>
#include <utility>
#include <algorithm>
using namespace std;
 
#define mod 1000000007
#define ll long long
#define tc int t; cin >> t; for(int tt = 1; tt <= t; tt++)
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
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

// Dirty Fix
// #define int long long
/*
    Problem link->
        https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/B

    Tested on Codeforces
    Warning Codeforces has weak testcase for this problem!
*/
void count_sort(vector<int>&p,vector<int>&c){
    int n = p.size();
    vector<int>cnt(n,0);
    for(int i = 0; i < n; i++){
        cnt[c[p[i]]]++;
    }
    int start_pos = 0;
    for(int i = 0; i < n; i++){
        int prev = cnt[i];
        cnt[i] = start_pos;
        start_pos += prev;
    }
    vector<int>new_p(n);
    for(int i = 0; i < n; i++){
        int ele = c[p[i]];
        new_p[cnt[ele]] = p[i];
        cnt[ele]++;
    }
    p = new_p;
    return;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    string str,str1;
    cin >> str >> str1;
    string s = str + '&' + str1 + '$';
    ll k = 0,n = s.length();
    vector<int> c(n),p(n);
    {
        vector<pair<int,int>>a(n);
        for(int i = 0; i < n; i++){
            a[i] = {s[i],i};
        }
        sort(a.begin(),a.end());
        c[a[0].second] = 0;
        p[0] = a[0].second;
        for(int i = 1; i < n; i++){
            p[i] = a[i].second;
            if(a[i].first != a[i - 1].first){
                c[a[i].second] = 1 + c[a[i - 1].second];
            }else{
                c[a[i].second] = c[a[i - 1].second];
            }
        }
    }
    ll mask = 1ll << k;
    while(mask < n){
        for(int i = 0; i < n; i++){
            p[i] = (p[i] - mask + n) % n;
        }
        count_sort(p,c);
        vector<int> new_c(n);
        new_c[p[0]] = 0; 
        for(int i = 1; i < n; i++){
            if(c[p[i]] == c[p[i - 1]] && c[(p[i] + mask) % n] == c[(p[i - 1] + mask) % n]){
                new_c[p[i]] = new_c[p[i - 1]];
            }else{
                new_c[p[i]] = 1 + new_c[p[i - 1]];
            }
        }
        c = new_c;
        k++;
        mask = (1ll << k);
    }
    vector<int> lcp(n - 1);
    ll matched = 0,len = 0,max_pos = -1;
    for(int i = 0; i < n - 1; i++){
        if(c[i] == 0){
            continue;
        }
        int prev_suffix = p[c[i] - 1]; 
        while(s[(i + matched)] == s[(prev_suffix + matched)]){
            matched++;
        }
        // If they belong to different class then compare maxlength found so far..
        if((prev_suffix > int(str.length()) && i < int(str.length()))
                 || (prev_suffix < int(str.length()) && i > int(str.length()))){
            if(len <= matched && matched > 0){
                if(len < matched){
                    max_pos = prev_suffix;
                }else if(len == matched && c[i] <= c[max_pos]){
                    max_pos = i;
                }
                len = matched;
            }
        }
        lcp[c[i] - 1] = matched;
        matched = max(0ll,matched - 1);
    }
    if(len == 0){
        cout << "" << endl;
    }else{
        cout << s.substr(max_pos,len) << endl;
    }
    return 0;
}
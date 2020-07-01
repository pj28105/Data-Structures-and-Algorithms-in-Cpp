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

void count_sort(vector<int>&p,vector<int>&c){
    int n = p.size(),cnt[n];
    memset(cnt,0,sizeof(cnt));
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

// Lower Bound in Suffix Array
int lb(string& s,vector<int>&p,string &x){
    int n = p.size();
    int st = 0,en = n - 1,ans = -1;
    while(st <= en){
        int mid = st + (en - st)/2;
        int matchCount = 0;
        for(int i = 0; i < int(x.length()); i++){
            char curr = s[(p[mid] + i) % n];
            if(curr < x[i]){
                st = mid + 1;
                break;
            }
            if(curr > x[i]){
                en = mid - 1;
                break;
            }
            matchCount++;
        }
        if(matchCount == int(x.length())){
            ans = mid;
            en = mid - 1;
        }
    }
    return ans;
}

// Upper Bound in Suffix Array
int ub(string& s,vector<int>&p,string &x){
    int n = p.size();
    int st = 0,en = n - 1,ans = -1;
    while(st <= en){
        int mid = st + (en - st)/2;
        int matchCount = 0;
        for(int i = 0; i < int(x.length()); i++){
            char curr = s[(p[mid] + i) % n];
            if(curr < x[i]){
                st = mid + 1;
                break;
            }
            if(curr > x[i]){
                en = mid - 1;
                break;
            }
            matchCount++;
        }
        if(matchCount == int(x.length())){
            ans = mid;
            st = mid + 1;
        }
    }
    return ans;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
    #endif
    string s;
    cin >> s;
    s += '$';
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
        vector<int>new_c(n);
        new_c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(c[p[i]] == c[p[i - 1]] && c[(p[i] + mask) % n] == c[(p[i - 1] + mask) % n]){
                new_c[p[i]] = new_c[p[i - 1]];
            }else{
                 new_c[p[i]] = new_c[p[i - 1]] + 1;
            }
        }
        c = new_c;
        k++;
        mask = 1ll << k;
    }
    ll q;
    cin >> q;
    while(q--){
        string x;
        cin >> x;
        int in_low = lb(s,p,x);
        if(in_low == -1){
            cout << 0 << endl;
        }else{
            int in_up = ub(s,p,x);
            cout << in_up - in_low + 1 << endl;
        }
    }
    return 0;
}
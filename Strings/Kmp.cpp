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
#define tc int t; cin >> t; while(t--)
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

/*
    KMP Algorithm
    Counts the occurrence of pattern in txt
    in O(n + m)
    Tested Status-> Positive
*/

signed main(void){
    string txt,patt;
    cin >> txt >> patt;
    int lps[patt.length()] = {}, i = 1,j = 0;
    while(i < patt.length()){
        if(patt[i] == patt[j]){
            lps[i] = j + 1;
            j++;
            i++;
        }else{
            if(j != 0){
                j = lps[j - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    int occ = 0;
    i = 0,j = 0;
    while(i < txt.length()){
        if(patt[j] == txt[i]){
            i++;
            j++;
        }else{
            if(j != 0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
        if(j == patt.length()){
            occ++;
            j = lps[j - 1];
        }
    }
    cout << occ << endl;
    return 0;
}
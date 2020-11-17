#include<stdio.h>
#include<algorithm>
using namespace std;
/*
    Problem link->
        https://www.spoj.com/problems/FREQ2/

    Note-> This question has very strict time limit.
        Always use scanf printf on spoj!
*/
const int MAX = 200011;
const int blk_siz = 317;
const int buff = 100005;

struct query{
    int first,second,in;
}q[MAX];

long long freq[MAX],max_cnt[MAX];

int main(void){
    int n,qq;
    scanf("%d %d",&n,&qq);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < qq; i++){
        scanf("%d %d",&q[i].first,&q[i].second);
        q[i].in = i;
    }
    sort(q,q + qq,[](query aa,query b)->bool{
        if((aa.first/blk_siz) != (b.first/blk_siz)){
            return (aa.first/blk_siz) < (b.first/blk_siz);
        }
        return aa.second < b.second;
    });
    int ans[qq];
    int ml = 0,mr = -1,currAns = 0;
    for(int i = 0; i < qq; i++){
        int l = q[i].first,r = q[i].second;
        while(ml < l){
            max_cnt[buff + freq[a[ml]]]--;
            if(max_cnt[buff + freq[a[ml]]] == 0){
                currAns--;
            }
            freq[a[ml]]--;   
            ml++;
        }
        while(l < ml){
            ml--;
            freq[a[ml]]++;
            if(max_cnt[buff + freq[a[ml]]] == 0){
                currAns++;
            }
            max_cnt[buff + freq[a[ml]]]++;
        }
        while(mr < r){
            mr++;
            freq[a[mr]]++;
            if(max_cnt[buff + freq[a[mr]]] == 0){
                currAns++;
            }
            max_cnt[buff + freq[a[mr]]]++;
        }
        while(r < mr){
            max_cnt[buff + freq[a[mr]]]--;
            if(max_cnt[buff + freq[a[mr]]] == 0){
                currAns--;
            }
            freq[a[mr]]--;
            mr--;
        }
        ans[q[i].in] = currAns;
    }
    for(int i = 0; i < qq; i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
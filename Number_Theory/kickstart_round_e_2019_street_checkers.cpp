// PJ28105

#include <iostream>
#include <vector>
using namespace std;
#define int long long

const int MAX = 31700;
bool primes[100005];
    
vector<int> p;
bool prim[MAX];

bool checkPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)
        return 0;
    }
    return 1;
}
    
void seive(){
    fill(prim,prim + MAX,true);
    prim[0] = prim[1] = false;
    for(int i = 2; i * i <= MAX; i++){
        if(prim[i]){
            for(int j = i * i; j < MAX; j += i){
                prim[j] = false;
            }
        }
    }
    p.emplace_back(2);
    for(int i = 3; i < MAX; i += 2){
        if(prim[i])
            p.emplace_back(i);
    }
}

void segmeneted_seive(int l,int r){
    fill(primes,primes + (r - l + 1),true);
    for(int i = 0; (p[i] * p[i]) <= r; i++){
        int currPrime = p[i], base = (l/currPrime) * currPrime;
        if(base < l){
            base += currPrime;
        }
        for(int j = base; j <= r; j += currPrime){
            primes[j - l] = false;
        }
        if(currPrime >= l && (currPrime - l) >= 0){
            primes[currPrime - l] = true;
        }
    }
    if(l <= 1 && r >= 1){
        primes[1 - l] = false;
    }
    if(l == 0){
        primes[0] = false;
    }
     int ans = 0;
    for(int i = l; i <= r; i++){
        if(i == 1 || i == 4 || i == 8){
            ans++;
        }
        else if(i % 2 == 0){
            int temp;
            if(i % 4 == 0){
                    temp = i/4; 
                    if(temp >= l && primes[temp - l])
                        ans += 1;
                    else if(checkPrime(temp))
                        ans+=1;
            }else{
                temp = i/2;
                if(temp % 2 != 0)
                    ans += 1;
            }
        }else if(primes[i - l]){
            ans += 1;
        }
    }
    printf("%lld\n",ans);
    return;
}

signed main()
{
   //freopen("../in.txt","r",stdin);
    seive();
    int t;
    scanf("%lld",&t);
    for(int tt = 1; tt <= t; tt++){
        int l,r;
        scanf("%lld %lld",&l,&r);
        printf("Case #%lld: ",tt);   
        segmeneted_seive(l,r);
    }  
    return 0;
}
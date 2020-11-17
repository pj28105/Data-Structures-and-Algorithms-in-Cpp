#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n,w;
        cin >> n >> w;
        // < Value, Weight> 
        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        /*
            Sorting on the basis of value/weight
        */
        sort(arr.begin(),arr.end(),[](pair<int,int>a,pair<int,int>b)->bool{
            return (a.first/(double)a.second) >= (b.first/(double)b.second);
        });
        double currval = 0;
        int currwt = 0;
        for(int i = 0; i < n; i++){
            if((arr[i].second + currwt) <= w){
                currval += arr[i].first;
                currwt += arr[i].second;
            }else{
                int rem = w - currwt; 
                currval += ((arr[i].first/(double)arr[i].second) * rem);
                currwt += rem;
            }
            if(currwt >= w){
                break;
            }
        }
        cout << fixed << setprecision(2) << currval << endl; 
    }
}
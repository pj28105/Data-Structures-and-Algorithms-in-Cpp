#include<bits/stdc++.h>
using namespace std;

int nextgap(int gap){
    if(gap <= 1){
        return 0;
    }
    return (gap >> 1) + (gap % 2);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int a[n],b[m];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int j = 0; j < m; j++){
            cin >> b[j];
        }
        int gap = nextgap(n + m),i = 0,j = 0;
        for(;gap >= 1; gap = nextgap(gap)){
            i = 0,j = 0;
            for(; (i + gap) < n; i++){
                if(a[i] > a[i + gap]){
                    swap(a[i],a[i + gap]);
                }
            }
            for(j = gap - n + i; i < n && j < m; j++,i++){
                if(a[i] > b[j]){
                    swap(a[i],b[j]);
                }
            }
            for(j = 0; (j + gap) < m; j++){
                if(b[j] > b[j + gap]){
                    swap(b[j],b[j + gap]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        for(int j = 0; j < m; j++){
            cout << b[j] << " ";
        }
        cout << endl;
    }
	return 0;
}
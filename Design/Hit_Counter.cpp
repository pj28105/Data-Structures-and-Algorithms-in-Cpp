/*
    Problem link->
        https://leetcode.com/problems/design-hit-counter/
    
    Tested on Leetcode!

    Note->
        1)This is most opitmized solution to this problem! (constant space and time)
        2) There are other solutions too with 
                    i)Queue (linear time and space)
                    ii)Binary Search (Logn time and linear space)
        check them on my leetcode submissions!
*/
class HitCounter {
public:
    
    int times[300],counter[300];
    HitCounter() {
        memset(times,0,sizeof(times));
        memset(counter,0,sizeof(counter));
    }
    
    void hit(int timestamp) {
        int idx = timestamp % 300;
        if(timestamp != times[idx]){
            times[idx] = timestamp;
            counter[idx] = 1; 
        }else{
            counter[idx]++;
        }
        return;
    }
    
    int getHits(int timestamp) {
        int ans = 0;
        for(int i = 0; i < 300; i++){
            if(times[i] > (timestamp - 300)){
                ans += counter[i];
            }
        }
        return ans;
    }
};
/*
    Problem link -> https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

    Tested on leetcode!
*/

class Solution {
public:
    
    bool isPossibleToShip(vector<int>& weights, int beltCapacity, int days) {
        int requiredDays = 1;
        int currBeltSpace = 0;
        for(int i  :  weights){
            if((currBeltSpace + i) > beltCapacity){
                currBeltSpace = i;
                requiredDays++;
            }else{
                currBeltSpace += i;
            }
        }
        
        return requiredDays <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxPossibleBeltCapacity = 0, minPossibleBeltCapacity = 0;
        for(int i : weights){
            maxPossibleBeltCapacity += i;
            minPossibleBeltCapacity = max(minPossibleBeltCapacity, i);
        }
        int result = 0;
        while(minPossibleBeltCapacity <= maxPossibleBeltCapacity){
            int mid = (minPossibleBeltCapacity + maxPossibleBeltCapacity)/2;
            if(isPossibleToShip(weights, mid, days)){
                maxPossibleBeltCapacity = mid - 1;
                result = mid;
            }else{
                minPossibleBeltCapacity = mid + 1;
            }
        }
        return result;
    }
};
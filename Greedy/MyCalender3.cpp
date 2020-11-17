/*
    Problem link->
        https://leetcode.com/problems/my-calendar-iii/

    Tested on Leetcode!
*/
class MyCalendarThree {
public:
    map<int,int>freq;
    MyCalendarThree() {
        freq.clear();
    }
    
    int book(int start, int end) {
        freq[start]++;
        freq[end]--;
        int currOverlap = 0,ans = 0;
        for(auto i : freq){
            currOverlap += i.second;
            ans = max(currOverlap,ans);
        }
        return ans;
    }
};

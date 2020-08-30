/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/third-largest-element/1/?track=amazon-arrays&batchId=192
    
    Tested on GFG

    This code also works for array with duplicates!
*/
int thirdLargest(int a[], int n){
    if(n < 3){
        return -1;
    }
    int max1,max2,max3;
    max1 = max2 = max3 = INT_MIN;
    for(int i = 0; i < n; i++){
        if(a[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        }else if(a[i] > max2 && max1 > a[i]){
            max3 = max2;
            max2 = a[i];
        }else if(a[i] > max3 && max2 > a[i]){
            max3 = a[i];
        }
    }
    return max3 == INT_MIN ? -1 : max3;
}

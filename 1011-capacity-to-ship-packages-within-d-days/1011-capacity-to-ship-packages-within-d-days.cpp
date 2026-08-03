class Solution {
    int daysreq(vector<int>&weights , int capacity){
       int days = 1 ;
       int load = 0;
       for(int w: weights){
        if(w+load>capacity){
            days++;
            load = w;
        }
        else{
            load+=w;
        }

       }
       return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int low = *max_element(weights.begin(), weights.end());
        // Find total sum as maximum capacity
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<high){
            int mid = (low+high)/2;
            int needed = daysreq(weights , mid);
            if(needed<=days){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
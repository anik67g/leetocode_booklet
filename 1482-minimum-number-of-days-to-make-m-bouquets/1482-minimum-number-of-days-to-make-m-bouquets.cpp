class Solution {
    int possible(vector<int>&arr , int day, int m ,int k){
        int no_of_boquests = 0;
        int cnt =0;
        for(int i = 0 ;i<arr.size();i++){

        
             if(arr[i]<=day){
                cnt++;

             }
             else{
                 no_of_boquests+= cnt/k;
                 cnt = 0;
             }


        }
         no_of_boquests += cnt / k;   // Count the last consecutive group

             return  no_of_boquests >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*k>n){
            return -1;
        }
       int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int low= mini; 
        int ans  = 0;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
if(possible(bloomDay,mid , m ,k)){
    ans = mid;
    high = mid-1; //  i want minimum so we go on a left side

    
}
else{
    low =mid+1;
}

        }
        return ans;
    }
};
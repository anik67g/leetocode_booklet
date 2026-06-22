class Solution {
public:
    long long findHours(vector<int>& piles, int speed){
        long long totalHours = 0;
        for(int i = 0; i<piles.size(); i++){
            if (piles[i] % speed == 0) totalHours += piles[i] / speed;
            else totalHours += (piles[i]/speed) + 1;
        }
        return totalHours;
    }
    int  findMax(vector<int>& piles){
        int maxElement = 0;
        for (int i = 0; i<piles.size(); i++){
            maxElement = max(maxElement, piles[i]);
        }
        return maxElement;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPiles = findMax(piles);
        int low = 1, high = maxPiles, minSpeed = maxPiles;
        long long checkHours;

        while (low <= high){
            long long mid = (low+high)/2;
            checkHours = findHours(piles, mid);
            if (checkHours <= h){
                minSpeed = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return minSpeed;
    }
};
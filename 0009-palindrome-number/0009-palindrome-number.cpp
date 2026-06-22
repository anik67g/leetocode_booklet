class Solution {
public:
    bool isPalindrome(int n) {
        int orginal=n;
        int rev=0;
        if (n<0) return false;
        while(n!=0){
            int ld=n%10;
            if ((rev>INT_MAX/10)||(rev<INT_MIN/10))
            return false;
            rev=rev*10+ld;
           n/=10;
        }
        if(rev==orginal) return true;
        else return false;
        
    }
};
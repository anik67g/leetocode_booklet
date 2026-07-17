class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int lastdigit = 0;
        int  sum1 = 0;
        int original = x;
        while(x>0){
            lastdigit = x%10;
            sum1 = sum1+lastdigit;
            x=x/10;
        }
        if(original%sum1==0){
            return sum1;
        }
        else{
            return -1;
        }

    }
};
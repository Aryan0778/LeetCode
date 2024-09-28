class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int temp=x;
        long long int sum=0;
        long long int digit;
        while(x!=0){
            digit=x%10;
            sum=(sum*10)+digit;
            x=x/10;
        }
        if(temp==sum)
            return true; 
        return false;
    }
};
class Solution {
public:
    int addDigits(int num) {
      while(num>=10){
        int ans=0,rem=0;
        while(num!=0){
            rem=num%10;
            num/=10;
            ans+=rem;
        }
        num=ans;
      }
      return num;  
    }
};
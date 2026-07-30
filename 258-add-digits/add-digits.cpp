class Solution {
public:
    int addDigits(int num) {
        while(num>=10)
        {
        int result=0;
        while(num!=0)
        {
            int n=num%10;
            num/=10;
            result+=n;
        }
        num=result;
        }

        return num ;
    }
};
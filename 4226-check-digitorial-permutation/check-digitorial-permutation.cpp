class Solution {
public:
int fact(int val)
{
    if(val==0)
    return 1;
    return val*fact(val-1);
}
    bool isDigitorialPermutation(int n) {
        int ans=0;
        int original_value=n;
        while(n>0)
        {
            int val=n%10;
            ans+=fact(val);
            n/=10;
        }
        string s1=to_string(original_value);
        string s2=to_string(ans);

        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        return s1==s2;
    }
};
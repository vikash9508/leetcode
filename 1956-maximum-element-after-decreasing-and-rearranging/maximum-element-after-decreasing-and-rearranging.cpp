class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int max_el=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(i==0){
            arr[0]=1;
            }
            else if(abs(arr[i]-arr[i-1])>1)
            {
                arr[i]=arr[i-1]+1;
            }
            max_el=max(max_el,arr[i]);
        }
        return max_el;
    }
};
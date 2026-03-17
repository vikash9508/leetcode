class Solution {
public:
void merge(vector<int>& arr,int start,int mid,int end){
    vector<int>temp(end-start+1);
    int left=start,right=mid+1,index=0;
    while(left<=mid&&right<=end)
    {
        if(arr[left]<=arr[right])
        {
            temp[index]=arr[left];
            index++,left++;
        }
        else{
            temp[index]=arr[right];
            index++,right++;
        }
    }
    //left array mai element agar baccha hua ho
    while(left<=mid)
    {
        temp[index]=arr[left];
        index++,left++;
    }
    //agar right array mai baccha hua ho toh
    while(right<=end)
    {
        temp[index]=arr[right];
        index++,right++;
    }
    //to fill element in original element
    index=0;
    while(start<=end)
    {
        arr[start]=temp[index];
        start++,index++;
    }

}
void mergesort(vector<int>& arr,int start,int end)
    {
        if(start==end)
        return;
        int mid=start + (end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);

    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};
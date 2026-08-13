class Solution {
    public boolean check(int[] nums) {
      int n=nums.length;
      int[] sorted=nums.clone();
      Arrays.sort(sorted);
      for(int i=0;i<n;i++)
      {
        boolean issorted=true;
        for(int j=0;j<n;j++)
        {
            if(sorted[j]!=nums[(i+j)%n])
            {
                issorted=false;
                break;
            }
        }
        if(issorted)
        {
            return true;
        }
      }  
      return false;
    }
}
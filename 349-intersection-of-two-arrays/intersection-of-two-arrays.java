class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer>st=new HashSet<>();
        List<Integer>result=new ArrayList<>();
        for(int num:nums1)
        {
            st.add(num);
        }
        for(int num:nums2)
        {
            if(st.contains(num))
            {
                result.add(num);
                st.remove(num);
            }
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
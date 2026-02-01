class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),water=0,maxleft=0,rightmax=0,maxheight=height[0],index=0;
        //finding maximum height
        for(int i=1;i<n;i++)
        {
            if(height[i]>maxheight)
            {
                maxheight=height[i];
                index=i;
            }
            
        }
        //left side
        for(int i=0;i<index;i++)
        {
            if(maxleft>height[i])
            water+=maxleft - height[i];
            else
            maxleft=height[i];
        }
        //right side
        for(int i=n-1;i>index;i--)
        {
            if(rightmax>height[i])
            water+=rightmax - height[i];
            else
            rightmax=height[i];
        }

       return water; 
    }
};
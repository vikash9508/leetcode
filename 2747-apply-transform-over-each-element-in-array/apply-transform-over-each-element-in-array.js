var map = function(arr, fn) {
    const arr1=[];
    for(let i=0;i<arr.length;i++)
    {
        arr1[i]=fn(arr[i],i);
    }
    return arr1;
};
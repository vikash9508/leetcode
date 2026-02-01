var filter = function(arr, fn) {
    const filteredarr=[];
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],i)){
            filteredarr.push(arr[i])
        }
    }
     return filteredarr;   
};
var flat = function (arr, n) {
    const result = [];

    function dfs(currentArr, depth) {
        for (let item of currentArr) {
            if (Array.isArray(item) && depth < n) {
                dfs(item, depth + 1);
            } else {
                result.push(item);
            }
        }
    }

    dfs(arr, 0);
    return result;
};

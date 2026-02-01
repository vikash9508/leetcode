var once = function(fn) {
    let count = 1;
    return function(...args) {
        if (count < 2) {
            count++;
            return fn(...args);
        }
        return undefined;
    };
};




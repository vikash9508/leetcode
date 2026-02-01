/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    // If it's not an object (primitive), return it directly
    if (obj === null || typeof obj !== "object") {
        return obj;
    }

    // Decide result type (array or object)
    const result = Array.isArray(obj) ? [] : {};

    for (let key in obj) {
        const value = compactObject(obj[key]);

        // Keep only truthy values
        if (Boolean(value)) {
            if (Array.isArray(result)) {
                result.push(value);
            } else {
                result[key] = value;
            }
        }
    }

    return result;
};

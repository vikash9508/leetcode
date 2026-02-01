/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
  const map = new Map();

  // put all arr1 objects
  for (const obj of arr1) {
    map.set(obj.id, obj);
  }

  // merge arr2 objects (override arr1 values)
  for (const obj of arr2) {
    if (map.has(obj.id)) {
      map.set(obj.id, { ...map.get(obj.id), ...obj });
    } else {
      map.set(obj.id, obj);
    }
  }

  // convert to array and sort by id
  return Array.from(map.values()).sort((a, b) => a.id - b.id);
};

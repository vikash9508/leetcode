/**
 * @param {Function[]} functions
 * @return {Promise<any[]>}
 */
var promiseAll = function (functions) {
  return new Promise((resolve, reject) => {
    const n = functions.length;
    const results = new Array(n);
    let completed = 0;
    let rejectedAlready = false;

    for (let i = 0; i < n; i++) {
      // Start all promises in parallel
      functions[i]()
        .then((val) => {
          if (rejectedAlready) return;

          results[i] = val;
          completed++;

          if (completed === n) {
            resolve(results);
          }
        })
        .catch((err) => {
          if (rejectedAlready) return;
          rejectedAlready = true;
          reject(err);
        });
    }
  });
};
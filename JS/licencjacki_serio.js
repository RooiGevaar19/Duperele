let N = 5; 
console.log(
    Array
        .apply(null, {length: N})
        .map(Number.call, Number)
        .map(function (x) { return Math.pow(x+1, 2); })
        .reduce((a, b) => a + b, 0)
);
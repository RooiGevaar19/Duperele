let N = 5; console.log(Array.apply(null, {length: N}).map(Number.call, Number).map(function (x) { return x+1; }).map(function (x) { return Math.pow(x, 2); }).reduce((a, b) => a + b, 0));
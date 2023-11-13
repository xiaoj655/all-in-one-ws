const curry = (fn) => {
  if (typeof fn !== "function") {
    throw new Error("provide not function");
  }
  return function curriedFn(...args) {
    if (args.length < fn.length) {
      return function () {
        return curriedFn.apply(null, args.concat(Array.from(arguments)));
      };
    }
    return fn.apply(null, args);
  };
};

const partical = (fn, ...particalArgs) => {
  if (typeof fn !== "function") {
    throw new Error("provide not function");
  }
  let args = particalArgs;
  return function (...fullArgs) {
    let k = 0;
    for (let i = 0; i < particalArgs.length && i < fn.length; i++) {
      if (args[i] == undefined) {
        args[i] = fullArgs[k++];
      }
    }
    return fn.apply(null, args);
  };
};

const hello = (a, b) => {
  console.log(a, "------", b);
};

const once = (fn) => {
  if (typeof fn !== "function") {
    throw new Error("provide not function");
  }
  let flag = false;
  return (...args) => {
    if (flag) {
      return;
    }
    flag = true;
    fn.apply(null, args);
  };
};

const say = () => {
  console.log("hello");
};

const memorize = (fn) => {
  if (typeof fn !== "function") {
    throw new Error("provide not function");
  }
  let mem = {};
  return (arg) => {
    return mem[arg] || (mem[arg] = fn(arg));
  };
};

const factorial = (x, accumulator = 1) => {
  if (x == 0 || x == 1) return accumulator;
  return factorial(x - 1, x * accumulator);
};

const fib = (x) => {
  if (x <= 1) return x;
  return fib(x - 1) + fib(x - 2);
};

const memFib = (x, memo = {}) => {
  if (x in memo) {
    return memo[x];
  }
  if (x <= 1) {
    return x;
  } else {
    return (memo[x] = memFib(x - 1, memo) + memFib(x - 2, memo));
  }
};

const compose = (...fns) => {
  return (...args) => {
    return fns.reduce((acc, fn, index) => {
      if (index == 0) {
        return acc;
      }
      return fn(acc);
    }, fns[0].apply(null, args));
  };
};

const sum = (x, y) => {
  return x + y;
};

const print = (x) => {
  console.log(x);
};

const sumFibPrint = compose(sum, fib, print);
sumFibPrint(2, 5);

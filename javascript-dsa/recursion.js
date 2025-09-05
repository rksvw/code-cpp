// WAP to find the factorial of N-th number
const fact = (num, dp) => {
  if (num === 1) {
    return num;
  }
  if (num === 2) {
    return num;
  }

  return num * dp[num - 2];
};

// WAP to find the factorial of N times of N-th numbers

const nOfNFactorial = (num) => {
  const nFact = [];

  for (let i = 1; i <= num; i++) {
    nFact.push(fact(i, nFact));
  }

  for (let i = 1; i <= num; i++) {
    console.log(`Factorial of ${i} = ${nFact[i - 1]}`);
  }
};

// WAP to find the fibonacci series of N-th number
const fibo = (num, dp) => {
  if (num === 0) {
    return 0;
  }

  if (num === 1) {
    return 1;
  }

  return dp[num - 1] + dp[num - 2];
};

// WAP to find the fibonacci series of N times of N-th numbers
const nOfNFibonacci = (num) => {
  const nFibo = [0, 1];

  for (let i = 2; i <= num; i++) {
    nFibo.push(fibo(i, nFibo));
  }

  for (let i = 0; i <= num; i++) {
    console.log(`Fibonacci of ${i} = ${nFibo[i]}`);
  }
};

nOfNFibonacci(100);

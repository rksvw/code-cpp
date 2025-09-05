// WAP to find the factorial of N-th number
const fact = (num, dp) => {
  return num * dp[num - 2];
};

// WAP to find the factorial of N times of N-th numbers

const nOfNFactorial = (num) => {
  const nFact = [1, 2];

  for (let i = 3; i <= num; i++) {
    nFact.push(fact(i, nFact));
  }

  for (let i = 1; i <= num; i++) {
    console.log(`Factorial of ${i} = ${nFact[i - 1]}`);
  }
};

// WAP to find the fibonacci series of N-th number
const fibo = (num, dp) => {
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
nOfNFactorial(100);

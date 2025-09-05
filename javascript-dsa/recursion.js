// WAP to find the factorial of N-th numbers
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

nOfNFactorial(1000);

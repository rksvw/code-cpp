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

// WAP to move the N-th disc from [source - destination] peg ( Tower of Hanoi )
const towerOfHanoi = (n, sourcePeg, destinationPeg, auxilaryPeg) => {
  if (n === 1) {
    console.log(`Move disc 1 from ${sourcePeg} to ${destinationPeg}`);
    return; // We're done with this base case
  }

  // Step 1: Move n-1 discs from Source to Auxiliary
  towerOfHanoi(n - 1, sourcePeg, auxilaryPeg, destinationPeg);

  // Step 2: Move the nth disc from Source to Destination
  console.log(`Move disc ${n} from ${sourcePeg} to ${destinationPeg}`);

  // Step 3: Move n-1 discs from Auxiliary to Destination
  towerOfHanoi(n - 1, auxilaryPeg, destinationPeg, sourcePeg);
};

// WAP to Search an element from list using Binary Search (RECURSIVE)
const binarySearch = (tar, list, left, right) => {
  const mid = (left + right) / 2;

  if (tar === list[mid]) {
    console.log("RESULT");
    return mid;
  } else if (tar < list[mid]) {
    console.log("CHOOSE LEFT");
    return binarySearch(tar, list, left, mid - 1);
  } else if (tar > list[mid]) {
    console.log("CHOOSE RIGHT");
    return binarySearch(tar, list, mid + 1, right);
  } else {
    console.log("NOT FOUND");
    return -1;
  }
};

const list = [
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
  23, 24, 25, 26, 27, 28, 29, 30,
];
// nOfNFibonacci(100);
// nOfNFactorial(100);
towerOfHanoi(3, "A", "C", "B");
console.log(binarySearch(2, list, 0, list.length));
console.log(binarySearch(30, list, 0, list.length));
console.log(binarySearch(26, list, 0, list.length));
console.log(binarySearch(21, list, 0, list.length));
console.log(binarySearch(37, list, 0, list.length));

module.exports = {
  nOfNFactorial,
  nOfNFibonacci,
  binarySearch
};

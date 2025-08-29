let studentMarks = [20, 45, 30, 25, 50, 60, 75, 1];
const sortStudentMarks = [20, 25, 30, 45, 50, 60, 75];

function reverseList(list) {
  const len = list.length;
  let start = 0;
  let end = len - 1;

  while (start < end) {
    swapItems(start, end, list);
    start++;
    end--;
  }

  return list;
}

function swapItems(idxA, idxB, list) {
  const value = list[idxA];
  list[idxA] = list[idxB];
  list[idxB] = value;
}

function rotateList(rotationSide, rotationStep, list) {
  const newArr = [];
  if (rotationSide == 0) {
    for (let i = rotationStep; i < list.length; i++) {
      newArr.push(list[i]);
    }

    for (let i = 0; i < rotationStep; i++) {
      newArr.push(list[i]);
    }
  } else {
    const len = list.length - rotationStep;

    for (let i = len; i < list.length; i++) {
      newArr.push(list[i]);
    }

    for (let i = 0; i < len; i++) {
      newArr.push(list[i]);
    }
  }

  return newArr;
}

function minItem(list) {
  let smallest = list[0];

  for (let i = 1; i < list.length; i++) {
    if (list[i] < smallest) {
      smallest = list[i];
    }
  }

  return smallest;
}

function maxItem(list) {
  let largest = list[0];

  for (let i = 1; i < list.length; i++) {
    if (list[i] > largest) {
      largest = list[i];
    }
  }

  return largest;
}

function linearSearch(target, list) {
  for (let i = 0; i < list.length; i++) {
    if (list[i] === target) {
      return i;
    }
  }

  return -1;
}

function binarySearch(target, list) {
  let start = 0;
  let end = list.length;

  while (start <= end) {
    let mid = Math.floor((start + end) / 2);

    if (target === list[mid]) {
      return mid;
    } else if (target < list[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return -1;
}

rotateList(1, 3, studentMarks).forEach((item) => console.log(item));
console.log("\n");
reverseList(studentMarks).forEach((item) => console.log(item));
console.log("\n");
console.log(minItem(studentMarks));
console.log("\n");
console.log(maxItem(studentMarks));
console.log("\n");
console.log(linearSearch(23, studentMarks));
console.log("\n");
console.log(binarySearch(60, sortStudentMarks));
console.log("\n");

function bubbleSort(list) {
  const len = list.length;

  for (let i = 0; i < len - 1; i++) {
    for (let j = 0; j < len - i - 1; j++) {
      if (list[j] > list[j + 1]) {
        let temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }
  }

  return list;
}

function insertionSort(list) {
  for (let i = 1; i < list.length; i++) {
    let key = list[i];
    let j = i - 1;

    while (j >= 0 && list[j] > key) {
      list[j + 1] = list[j];
      j--;
    }
    list[j + 1] = key;
  }
  return list;
}

insertionSort([4, 1, 2, 7, 6, 3, 5]).forEach((item) => console.log(item));
console.log("\n");

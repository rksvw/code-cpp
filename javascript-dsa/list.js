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

function selectionSort(list) {
  for (let i = 0; i < list.length; i++) {
    let minIdx = i;
    for (let j = i + 1; j < list.length; j++) {
      if (list[j] < list[minIdx]) {
        minIdx = j;
      }
    }

    let temp = list[i];
    list[i] = list[minIdx];
    list[minIdx] = temp;
  }
  return list;
}

module.exports = {
  bubbleSort,
  selectionSort,
  insertionSort,
};

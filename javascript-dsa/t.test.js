import { describe, test, it, expect } from "vitest";
import { bubbleSort, insertionSort, selectionSort } from "./list";

describe("Bubble Sort", () => {
  it("should return sorted list", () => {
    const list = [1, 4, 3, 7, 5, 6, 2];

    const result = bubbleSort(list);
    expect(result).toStrictEqual([1, 2, 3, 4, 5, 6, 7]);
  });

  it("should return sorted list 2", () => {
    const list = [5, -5, 8, -20, 7, 3, 5, 2, 1, 6];
    const result = bubbleSort(list);

    expect(result).toStrictEqual([-20, -5, 1, 2, 3, 5, 5, 6, 7, 8]);
  });
});

describe("Selection Sort", () => {
  it("should return sorted list", () => {
    const list = [1, 4, 3, 7, 5, 6, 2];

    const result = selectionSort(list);
    expect(result).toStrictEqual([1, 2, 3, 4, 5, 6, 7]);
  });

  it("should return sorted list 2", () => {
    const list = [5, -5, 8, -20, 7, 3, 5, 2, 1, 6];
    const result = selectionSort(list);

    expect(result).toStrictEqual([-20, -5, 1, 2, 3, 5, 5, 6, 7, 8]);
  });
});

describe("Insertion Sort", () => {
  it("should return sorted list", () => {
    const list = [1, 4, 3, 7, 5, 6, 2];

    const result = insertionSort(list);
    expect(result).toStrictEqual([1, 2, 3, 4, 5, 6, 7]);
  });

  it("should return sorted list 2", () => {
    const list = [5, -5, 8, -20, 7, 3, 5, 2, 1, 6];
    const result = insertionSort(list);

    expect(result).toStrictEqual([-20, -5, 1, 2, 3, 5, 5, 6, 7, 8]);
  });
});

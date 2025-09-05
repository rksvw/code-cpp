import { describe, test, it, expect } from "vitest";
import { bubbleSort, insertionSort, selectionSort } from "./list";
import { longestSubStr, palindrome, reverseString } from "./str";

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

describe("String Problem", () => {
  it("WAP to check the string is a palindrome or not", () => {
    const str = "racecar";
    const result = palindrome(str);

    expect(result).toBe(true);
  });

  it("WAP to check the string is a palindrome or not 2", () => {
    const str = "RaCeCAr";
    const result = palindrome(str);

    expect(result).toBe(true);
  });

  it("WAP to check the string is a palindrome or not 3", () => {
    const str = "milo";
    const result = palindrome(str);

    expect(result).toBe(false);
  });

  it("Check palindrome is Empty", () => {
    const str = "";
    const result = palindrome(str);

    expect(result).toBe(false);
  });

  it("Check palindrome is Number", () => {
    const str = 5;
    const result = palindrome(str);

    expect(result).toBe(false);
  });

  it("Check palindrome is Array of integer", () => {
    const str = [1, 5, 9];
    const result = palindrome(str);

    expect(result).toBe(false);
  });
});

describe("Reverse String", () => {
  it("Sould reverse the string 'Meow' -> 'woeM' ", () => {
    const str = "Meow";
    const result = reverseString(str);

    expect(result).toBe("woeM");
  });

  it("Should reverse the string 'newcar' -> 'racwen' ", () => {
    const str = "newcar";
    const result = reverseString(str);

    expect(result).toBe("racwen");
  });
});

describe("Longest Substring without duplicates", () => {
  it("Test 1 : 'abcabc' -> 3", () => {
    const str = "abcabc";
    const result = longestSubStr(str);

    expect(result).toBe(3);
  });

  it("Test 2 : 'pwwkew' -> 3", () => {
    const str = "pwwkew";
    const result = longestSubStr(str);

    expect(result).toBe(3);
  });
  it("Test 2 : 'dvdf' -> 3", () => {
    const str = "dvdf";
    const result = longestSubStr(str);

    expect(result).toBe(3);
  });
  it("Test 2 : 'bbbbb' -> 1", () => {
    const str = "bbbbb";
    const result = longestSubStr(str);

    expect(result).toBe(1);
  });
  it("Test 2 : ' ' -> 3", () => {
    const str = " ";
    const result = longestSubStr(str);

    expect(result).toBe(1);
  });
  it("Test 2 : 'ldadkidcnjhska' -> 9", () => {
    const str = 'ldadkidcnjhska';
    const result = longestSubStr(str);

    expect(result).toBe(9)
  })

});

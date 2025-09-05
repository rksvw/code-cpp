const palindrome = (str) => {
  if (str.length === 0 || Number(str) || Number(str[0])) {
    return false;
  }

  let st = 0;
  let en = str.length - 1;

  while (st <= en) {
    if (str[st].toLowerCase() !== str[en].toLowerCase()) {
      return false;
    }
    st = st + 1;
    en = en - 1;
  }

  return true;
};

const reverseString = (str) => {
  let listStr = [];

  for (let i = str.length - 1; i >= 0; i--) {
    listStr.push(str[i]);
  }
  return listStr.join("");
};

// Original and more optimal code for Longest substring without duplicates which uses Sliding window approach
const longestSubStr = (str) => {
  let uniqueChar = new Set();
  let left = 0;
  let maxLen = 0;

  for (let right = 0; right < str.length; right++) {
    while (uniqueChar.has(str[right])) {
      uniqueChar.delete(str[left]);
      left++;
    }

    uniqueChar.add(str[right]);
    maxLen = Math.max(maxLen, right - left + 1);
  }

  return maxLen;
};

// Not optimal | Buggy code for Longest substring without repeating character.
const longestSubStrBuggy = (str) => {
  let uniqueChar = new Set();
  let listChar = [];
  let listStr = [];

  for (let i = 0; i < str.length; i++) {
    if (!uniqueChar.has(str[i])) {
      uniqueChar.add(str[i]);
      listChar.push(str[i]);
      // console.log(str[i] === " ")
    } else {
      listStr.push(listChar.join(""));
      listChar = [];
      listChar.push(str[i]);
    }
  }

  if (listChar.length > 0) {
    listStr.push(listChar.join(""));
    listChar = [];
  }

  let largest = 0;

  for (let i = 0; i < listStr.length; i++) {
    if (listStr[i].length >= largest) {
      largest = listStr[i].length;
    }
  }
  console.log("Str", listStr);
  console.log("Char", largest);
  console.log("Unique", uniqueChar);
  return largest;
};

longestSubStr("ckilbkd");
longestSubStr("abcabcbb");
longestSubStr("bbbbb");
longestSubStr("pwwkew");
longestSubStr("dvdf");
longestSubStr(" ");

module.exports = { palindrome, reverseString, longestSubStr };

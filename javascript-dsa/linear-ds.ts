function reverseString(str: String): String {
  const reverseStr: Array<String> = [];
  for (let i = 0; i < str.length; i++) {
    reverseStr.push(str[str.length - i - 1]);
  }

  return reverseStr.join("");
}

function revStr(str: String): String {
  const stack: Array<String> = [];
  let result: any = "";

  for (let i = 0; i < str.length; i++) {
    stack.push(str[i]);
  }

  while (stack.length > 0) {
    let item = stack.pop();
    result = result.concat(item);
  }

  return result;
}

console.log(reverseString("Hello World"));
console.log(revStr("hello"));

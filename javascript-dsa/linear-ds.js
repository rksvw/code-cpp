function reverseString(str) {
    var reverseStr = [];
    for (var i = 0; i < str.length; i++) {
        reverseStr.push(str[str.length - i - 1]);
    }
    return reverseStr.join("");
}
function revStr(str) {
    var stack = [];
    var result = "";
    for (var i = 0; i < str.length; i++) {
        stack.push(str[i]);
    }
    while (stack.length > 0) {
        var item = stack.pop();
        result = result.concat(item);
    }
    return result;
}
console.log(reverseString("Hello World"));
console.log(revStr("hello"));

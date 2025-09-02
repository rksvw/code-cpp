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

module.exports = { palindrome };

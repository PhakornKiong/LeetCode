// https://leetcode.com/problems/palindrome-number/

// Best
// Time - O(n) -- O(log10(n))
// Space - O(1)
var isPalindrome = function (x) {
  if (x < 0) return false
  let reversed = 0
  let remainder
  let original = x

  while (x > 0) {
    remainder = x % 10
    reversed = reversed * 10 + remainder
    x = Math.floor(x / 10)

  }
  return original == reversed
};

// Alternative - String method
function splitNum(num) {
  return String(num).split("").map(Number);
}

var isPalindrome = function (x) {
  if (x < 0) return false

  const arr = splitNum(x)
  const iterArr = arr.length - 1
  let n = 0
  while (true) {
    if ((arr[n] ^ arr[iterArr - n]) === 0) {
      if (n >= iterArr) {
        return true
      }
      n++
      continue
    } else {
      return false
    }
  }
};
// https://leetcode.com/problems/palindrome-number/

// Best
// Time - O(n) -- O(log10(n))
// Space - O(1)
class Solution
{
public:
  bool isPalindrome(int x)
  {
    int original = x;
    if (x < 0)
      return false;

    long long reversed = 0;
    while (x >= 10)
    {
      reversed = reversed * 10 + x % 10;
      x /= 10;
    }
    reversed = reversed * 10 + x;
    return reversed == original;
  }
};

// Similar, much concise
class Solution
{
public:
  bool isPalindrome(int x)
  {
    int original = x;
    if (x < 0)
      return false;

    long long reversed = 0;
    while (x > 0)
    {
      reversed = reversed * 10 + x % 10;
      x /= 10;
    }

    return reversed == original;
  }
};
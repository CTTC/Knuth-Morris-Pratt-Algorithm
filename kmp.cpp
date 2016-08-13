#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

void computePrefixFunction(const string& pattern, vector<int>& s)
{
  s[0] = 0;
  int border = 0;
  for (int i = 1; i < pattern.size(); i++)
  {
    while (border > 0 && pattern[i] != pattern[border])
    {
      border = s[border - 1];
    }
    if (pattern[i] == pattern[border])
    {
      border++;
    }
    else
    {
      border = 0;
    }
    s[i] = border;
  }
}

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  string combinedString = pattern + '$' + text;
  vector<int> s(combinedString.size(), 0);
  computePrefixFunction(combinedString, s);
  int length = pattern.size();
  for (int i = length + 1; i < combinedString.size(); i++)
  {
    if (s[i] == length)
    {
      result.push_back(i - 2 * pattern.size());
    }
  }

  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}

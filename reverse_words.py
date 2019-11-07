class Solution:
  def reverseWords(self, string):
    reverse_words = []

    for word in string.split(' '):
        word = word[-1::-1]
        reverse_words.append(word)

    return ' '.join(reverse_words)

print(Solution().reverseWords("The cat in the hat"))
# ehT tac ni eht tah

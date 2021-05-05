class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int: 
        if endWord not in wordList:
            return 0
        queue = collections.deque([beginWord])
        visited = set([beginWord])
        pathLength = 1
        
        while queue:
            for _ in range(len(queue)):
                currentWord = queue.popleft()
                for word in wordList:
                    if word not in visited and self.isValidTransfer(currentWord, word):
                        if word == endWord:
                            return pathLength + 1
                        visited.add(word)
                        queue.append(word)
            pathLength += 1
        
        return 0
    
    def isValidTransfer(self, currentWord, word):
        diff_number = 0
        for i in range(len(currentWord)):
            if currentWord[i] != word[i]:
                diff_number += 1
            if diff_number > 1:
                return False
        return diff_number == 1

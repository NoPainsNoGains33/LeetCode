class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int: 
        if endWord not in wordList:
            return 0
        queue = collections.deque([beginWord])
        visited = set([beginWord])
        wordSet = set(wordList)
        pathLength = 1
        
        while queue:
            for _ in range(len(queue)):
                currentWord = queue.popleft()
                nextWords = self.findNext(currentWord, wordSet, visited)
                for nextWord in nextWords:
                    if nextWord == endWord:
                        return pathLength + 1
                    visited.add(nextWord)
                    queue.append(nextWord)
            pathLength += 1
        
        return 0
    
    def findNext(self, currentWord, wordSet, visited):
        nextWords = []
        alphabets = "abcdefghijklmnopqrstuvwxyz"
        for i in range(len(currentWord)):
            for alphabet in alphabets:
                if alphabet == currentWord[i]:
                    continue
                nextWord = currentWord[:i] + alphabet + currentWord[i + 1 : len(currentWord)]
                if nextWord in wordSet and nextWord not in visited:
                    nextWords.append(nextWord)
        
        return nextWords

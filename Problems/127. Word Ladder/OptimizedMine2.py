class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int: 
        if endWord not in wordList:
            return 0
        queue = collections.deque([beginWord])
        distance = {beginWord : 1}
        wordSet = set(wordList)
        
        while queue:
            currentWord = queue.popleft()
            nextWords = self.findNext(currentWord, wordSet, distance)
            for nextWord in nextWords:
                if nextWord == endWord:
                    return distance[currentWord] + 1
                distance[nextWord] = distance[currentWord] + 1
                queue.append(nextWord)
        
        return 0
    
    def findNext(self, currentWord, wordSet, distance):
        nextWords = []
        alphabets = "abcdefghijklmnopqrstuvwxyz"
        for i in range(len(currentWord)):
            left, right = currentWord[:i], currentWord[i + 1:]
            for alphabet in alphabets:
                if alphabet == currentWord[i]:
                    continue
                nextWord = left + alphabet + right
                if nextWord in wordSet and nextWord not in distance:
                    nextWords.append(nextWord)
        
        return nextWords

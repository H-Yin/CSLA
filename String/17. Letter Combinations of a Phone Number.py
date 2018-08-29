
'''
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
'''
# python3
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        maps = {'2':['a','b','c'], '3':['d','e','f'], '4':['g','h','i'],
                '5':['j','k','l'],'6':['m','n','o'], '7':['p','q','r','s'],
                '8':['t','u','v'], '9':['w','x','y','z']}
        res=[]
        for i in digits:
            if len(res) == 0:
                res.extend(maps[i])
            else:
                temp = [x+y for x in res for y in maps[i]]
                res = temp
        return res

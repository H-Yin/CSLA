/* 17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        map<char, vector<char>> maps;
        maps['2'] = vector<char>({'a','b','c'});
        maps['3'] = vector<char>({'d','e','f'});
        maps['4'] = vector<char>({'g','h','i'});
        maps['5'] = vector<char>({'j','k','l'});
        maps['6'] = vector<char>({'m','n','o'});
        maps['7'] = vector<char>({'p','q','r','s'});
        maps['8'] = vector<char>({'t','u','v'});
        maps['9'] = vector<char>({'w','x','y','z'});
        for(int i = 0 ;i < digits.length() ;i++){
            if(res.size() == 0){
                for(int j=0; j<maps[digits[i]].size(); j++){
                    res.push_back(string(1,maps[digits[i]][j]));
                }
            }else{
                vector<string> tmp;
                for(int k=0; k< res.size();k++){
                    for(int j=0; j<maps[digits[i]].size(); j++){
                        tmp.push_back(res[k]+string(1,maps[digits[i]][j]));
                    } 
                }
                res.clear();
                res.insert(res.begin(),tmp.begin(),tmp.end());
            }
        }
        return res;
    }
};

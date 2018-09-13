/*
165. Compare Version Numbers
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/

class Solution:
    def compareVersion(self, version1, version2):
        ans = 0
        v1 = list(map(int,version1.split('.')))
        v2 = list(map(int,version2.split('.')))
        len_v1,len_v2 = len(v1),len(v2)
        min_len = len_v1 if len_v1 < len_v2 else len_v2

        for i in range(min_len):
            if v1[i] > v2[i]:
                ans = 1;
                break;
            elif v1[i] < v2[i]:
                ans = -1;
                break;
            else:
                continue
        
        if ans == 0:
            if len_v1 < len_v2:
                ans = -1 if sum(v2[len_v1:len_v2]) > 0 else 0
            else:
                ans = 1 if sum(v1[len_v2:len_v1]) > 0 else 0
        return ans

//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    int go (string s, int l, int r) {
        while (l >=0 and r < s.size() and s[l] == s[r]) l--,r++;
        return r-l-1;
    } 
    string longestPalindrome(string s) {
        int st=0,en=0;
        for (int mid=0; mid<s.size();mid++) {
            int len1 = go(s,mid,mid);
            int len2 = go(s,mid,mid+1);
            int len=max(len1,len2);
            if (len > en-st) {
                st = mid - (len-1)/2; en = mid + len/2;
            }
        }
        return s.substr(st, en-st+1);
    }
};

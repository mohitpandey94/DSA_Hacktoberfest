package Leetcode;

import java.util.HashMap;
import java.util.Map;

public class LongestSubstringWithoutRepeatingCharacters {
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        Map<Character, Integer> mp = new HashMap<>();
        int prev = 0;
        int cur_len = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(mp.containsKey(s.charAt(i))&& mp.get(s.charAt(i)) >= 1)
            {
                while(s.charAt(prev) != s.charAt(i))
                {
                    mp.put(s.charAt(prev),mp.get(s.charAt(prev)) -1);
                    prev++;
                    cur_len--;
                }
                prev++;
            }
            else
            {
                mp.put(s.charAt(i),1);
                cur_len++;
            }

            res = Math.max(res,cur_len);

        }
        return res;
    }

    public static void main(String[] args) {
        String s = "abcabcbb";
        System.out.println(new LongestSubstringWithoutRepeatingCharacters().lengthOfLongestSubstring(s));
    }
}

package Leetcode;

import java.util.*;

public class GroupAnagramTogether {
    public List<List<String>> groupAnagrams(String[] strs) {
        int i = 0;
        String copy[] = strs.clone();
        HashSet<String>set = new HashSet<>();
        for(i = 0; i < strs.length; i++)
        {
            char a[] = strs[i].toCharArray();
            Arrays.sort(a);
//            strs[i] = new String(a);
            set.add(new String(a));
        }
        List<List<String>>res = new ArrayList<>();

        Map<String, List<String>>mp = new HashMap<>();
        for(String st: set)
        {
            List<String>l = new LinkedList<>();
            mp.put(st,l);
        }

        for(i = 0; i < strs.length; i++)
        {
            char a[] = strs[i].toCharArray();
            Arrays.sort(a);
            mp.get(new String(a)).add(strs[i]);
        }
        Iterator<Map.Entry<String, List<String>>> itr = mp.entrySet().iterator();

        while(itr.hasNext())
        {
            res.add(itr.next().getValue());
        }
        return res;
    }

    public static void main(String[] args) {
        String arg[] = new String[]{"eat", "tea", "tan", "ate", "nat", "bat"};
        new GroupAnagramTogether().groupAnagrams(arg);
    }
}

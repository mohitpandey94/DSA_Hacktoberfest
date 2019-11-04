package Leetcode;

import java.util.ArrayList;
import java.util.Scanner;

public class Stoi {
    public int myAtoi(String str) {
        int n = str.length();
        int i = 0;
        while(i < n && str.charAt(i) == ' ')
        {
            i++;
        }
        ArrayList<Integer>buf = new ArrayList<>();
        while(i < n && str.charAt(i) != ' ')
        {
            char c = str.charAt(i);
            buf.add(c-'0');
            i++;
        }
        int sz = buf.size();

        int res = 0;
        int sum = 0;
        int ctr = 0;
        for( i = 0; i < sz; i++)
        {
            sum = res*10;
            res = sum + buf.get(i);
        }

        return res;
    }

    public static void main(String[] args) {
        String str = new Scanner(System.in).nextLine();
        int res = new Stoi().myAtoi(str);
        System.out.println(res);
    }
}

package gspractice;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class FirstNonRepeatingCharacter {
    static Scanner scanner;
    Map<Character,Integer>mp = new HashMap<>();
    private void printFirstNonRepeatingCharacter(String input)
    {
        for(int i = 0; i < input.length(); i++){
            if(mp.containsKey(input.charAt(i)))
            {
                mp.put(input.charAt(i),mp.get(input.charAt(i))+1);
            }
            else
            {
                mp.put(input.charAt(i),1);
            }
        }

        for(int i = 0; i < input.length(); i++)
        {
            if(mp.get(input.charAt(i)) == 1)
            {
                System.out.println(input.charAt(i));
                return;
            }
        }

        System.out.println(-1);
    }
    public static void main(String args[])
    {
        scanner = new Scanner(System.in);
        int t;
        t = scanner.nextInt();
        int prev = t;
        while(t > 0)
        {
            t--;
            int length = scanner.nextInt();
            scanner.nextLine();
            String input = scanner.nextLine();
            FirstNonRepeatingCharacter ob = new FirstNonRepeatingCharacter();
            ob.printFirstNonRepeatingCharacter(input);
        }
    }
}

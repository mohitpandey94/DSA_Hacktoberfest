package Leetcode;

import java.util.Scanner;

public class ContainerWithMostWater {
    public int maxArea(int[] a) {
        int n = a.length;
        int r[] = new int[n];
        r[n-1] = n-1;

        for(int i = n-2; i >= 0; i--)
        {
            if(a[i] <= a[r[i+1]])
            {
                r[i] = r[i+1];
            }
            else
            {
                r[i] = i;
            }
        }
/*
7
2 3 4 5 18 17 6

9
1 8 6 2 5 4 8 3 7
 */
        int l[] = new int [n];
        l[0] = 0;
        for(int i = 1; i < n; i++)
        {
            if(a[i] <= a[l[i-1]])
            {
                l[i] = l[i-1];
            }
            else
            {
                l[i] = i;
            }
        }
        System.out.println("Left Array");
        for(int i = 0; i < n; i++)
        {
            System.out.print(l[i]+ ", ");
        }

        System.out.println();
        System.out.println("Right Array");
        for(int i = 0; i < n; i++)
        {
            System.out.print(r[i]+ ", ");
        }
        System.out.println();
        int cur_max = a[0];
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res = Math.max(Math.min(a[r[i]], a[l[i]]) * ((r[i] - l[i])) , res);
            System.out.println("i = "+i+" , res= "+res);
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];

        for(int i = 0; i < n; i++)
        {
            a[i] = sc.nextInt();
        }

        int res = new ContainerWithMostWater().maxArea(a);
        System.out.println(res);
    }
}

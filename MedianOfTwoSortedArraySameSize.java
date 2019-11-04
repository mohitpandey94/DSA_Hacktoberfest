package Leetcode;

import java.util.Scanner;

import static java.lang.Integer.max;

public class MedianOfTwoSortedArraySameSize {
    static int a[];
    static int b[];
    static Scanner sc  = null;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        int n = sc.nextInt();
        a = new int[n];
        b = new int[n];

        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        for(int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }

        System.out.println(new MedianOfTwoSortedArraySameSize().findMedian(0, n-1, 0, n-1));
    }

    int findMedian(int l1, int r1, int l2, int r2) {

        int m1,m2;
        m1 = m2 = 0;
        if(r1 - l1 == 1) {
            return (Math.max(a[l1],b[l2]) + Math.min(a[r1],b[r2]))/2;
        }
        if ((r1-l1+1)%2 == 0) {
            m1 = (a[(l1+r1)/2] + a[(l1+r1)/2 + 1])/2;
            m2 = (b[(l2+r2)/2] + b[(l2+r2)/2 + 1])/2;
        }
        else {
            m1 = a[(l1+r1)/2];
            m2 = b[(l2+r2)/2];
        }

        if(m1 == m2) {
            return m1;
        } else if(m1 > m2) {
            if((r1-l1+1)%2 == 0)
                return findMedian(l1, (l1+r1)/2, (l2+r2)/2 + 1, r2 );
            else
                return findMedian(l1, (l1+r1)/2, (l2+r2)/2, r2);
        } else {
            if((r1-l1+1)%2 == 0)
                return findMedian((l1+r1)/2 + 1, r1, l2, (l2+r2)/2);
            else
                return findMedian((l1+r1)/2, r1, l2, (l2+r2)/2);
        }


    }
}

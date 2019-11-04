package gspractice;

import java.util.Scanner;

public class TrappingRainWater {
    public int trap(int[] height) {
        int n = height.length;
        int left[] = new int[n];
        int right[] = new int[n];

        left[0] = height[0];
        right[n-1] = height[n-1];

        for(int i = 1; i < n; i++)
        {
            left[i] = Math.max(height[i],left[i-1]);
        }

        for(int i = n-2; i >= 0; i--)
        {
            right[i] = Math.max(height[i],right[i+1]);
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int min_height = Math.min(left[i], right[i]);
            res+=(min_height-height[i]);
        }
        return res;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int height[] = new int[n];

        for(int i = 0; i < n; i++)
        {
            height[i] = sc.nextInt();
        }

        TrappingRainWater ob = new TrappingRainWater();
        System.out.println(ob.trap(height));
    }
}

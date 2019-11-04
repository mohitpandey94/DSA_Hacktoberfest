package Leetcode;

import java.util.Arrays;
import java.util.Comparator;

public class MergeIntervals {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0] > o2[0])
                {
                    return 1;
                }
                else if(o1[0] == o2[0])
                {
                    if(o1[1] > o2[0])
                        return 1;
                    else
                        return -1;
                }
                else
                    return -1;
            }
        });

        int m = intervals.length;
        if(m == 0 || m ==1)
        {
            return intervals;
        }
        int n = 2;
        int a[][] = new int[m][2];
        int ctr = 0;
        a[0][0] = intervals[0][0];
        a[0][1] = intervals[0][1];
        for(int i = 1; i < m; i++)
        {
            if(intervals[i][0] <= a[ctr][1])
            {
                a[ctr][1] = Math.max(intervals[i][1],a[ctr][1]);
            }
            else
            {
                ctr++;
                a[ctr][0] = intervals[i][0];
                a[ctr][1] = intervals[i][1];
            }
        }
        int res[][] = new int[ctr+1][2];

        for(int i = 0; i <= ctr; i++)
        {
            res[i][0] = a[i][0];
            res[i][1] = a[i][1];
        }

        return res;
    }

    public static void main(String[] args) {
        int arg[][] = {{1,3},{2,6},{8,10},{15,18}};
        int res[][] = new MergeIntervals().merge(arg);
    }
}

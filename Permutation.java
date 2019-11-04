package Leetcode;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;



public class Permutation {
    List<Integer>fnc(List<Integer>a, int i, int n)
    {
        if(i == n - 1)
        {
            return a;
        }
        for(int j = i; j < n; j++)
        {
            Collections.swap(a,i,j);
            fnc(a,j+1,n);
        }
        return a;
    }
    public List<List<Integer>> permute(int[] nums) {

        int n = nums.length;
        List<Integer>a = new LinkedList<>();
        for(int i: nums)
        {
            a.add(i);
        }
        List<List<Integer>>res = new LinkedList<>();
        List<Integer>temp = new LinkedList<>();
        for(int i = 0; i < n; i++)
        {
            res.add(fnc(a,i, n));
        }

        return res;
    }

    public static void main(String[] args) {
        int a[] = {1,2,3};
        List<List<Integer>>res = new Permutation().permute(a);
        System.out.println(res);
    }
}

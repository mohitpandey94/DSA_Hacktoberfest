package gspractice;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


class Pair1
{
    public int getLeft() {
        return left;
    }

    public void setLeft(int left) {
        this.left = left;
    }

    public int getRight() {
        return right;
    }

    public void setRight(int right) {
        this.right = right;
    }

    int left;
    int right;
}

public class ArraySumEqualToANumberDummy {
    private ArrayList<Pair>findSubarraysWithGivenSumDummy(int a[], int sum)
    {
        ArrayList<Pair>res = new ArrayList<>();
        Map<Integer,Integer>sumMap = new HashMap<>();

        int curSum = a[0];
        sumMap.put(curSum,0);

        if(curSum == sum) {
            Pair ob = new Pair();
            ob.setLeft(0);
            ob.setRight(0);
            res.add(ob);
            return res;
        }

        for(int i = 1; i < a.length; i++){
            curSum+=a[i];
            sumMap.put(curSum,i);
            if(curSum == sum)
            {
                Pair ob = new Pair();
                ob.setLeft(0);
                ob.setRight(i);
                res.add(ob);
            }
            else if(sumMap.containsKey(curSum - sum))
            {
                Pair ob = new Pair();
                ob.setLeft(sumMap.get(curSum - sum)+1);
                ob.setRight(i);
                res.add(ob);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int t;
        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();

        while(t > 0)
        {
            t--;
            int n = scanner.nextInt();
            int a[] = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = scanner.nextInt();
            }
            int sum = scanner.nextInt();
            ArraySumEqualToANumberDummy ob = new ArraySumEqualToANumberDummy();
            ArrayList<Pair>result = ob.findSubarraysWithGivenSumDummy(a,sum);
            System.out.println(result.size());
        }

    }
}

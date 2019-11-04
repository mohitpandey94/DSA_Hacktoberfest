package gspractice;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


class Pair
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
public class ArraySumEqualToANumber {

    private ArrayList<Pair>findSubarraysWithGivenSum(int a[], int sum)
    {
        ArrayList<Pair>res = new ArrayList<>();
        Map<Integer,ArrayList<Integer> >sumMap = new HashMap<>();


        int curSum = a[0];
        ArrayList<Integer>temp = new ArrayList<>();
        temp.add(0);
        sumMap.put(curSum,temp);

        if(curSum == sum) {
            Pair ob = new Pair();
            ob.setLeft(0);
            ob.setRight(0);
            res.add(ob);
        }

        for(int i = 1; i < a.length; i++){
            curSum+=a[i];


            if(curSum == sum)
            {
                Pair ob = new Pair();
                ob.setLeft(0);
                ob.setRight(i);
                res.add(ob);
            }
            else if(sumMap.containsKey(curSum - sum))
            {

                for(int j = 0; j < sumMap.get(curSum - sum).size(); j++)
                {
                    Pair ob = new Pair();
                    ob.setLeft(sumMap.get(curSum - sum).get(j)+1);
                    //System.out.println("curSum : " + curSum + "   left: " + ob.getLeft() + "  right: " + i);
                    ob.setRight(i);
                    res.add(ob);
                }
            }
            if(sumMap.containsKey(curSum))
            {
                //tmp = sumMap.get(curSum);
                sumMap.get(curSum).add(i);
                //tmp.add(i);
                //sumMap.put(curSum,tmp);
            }
            else {
                ArrayList<Integer>tmp = new ArrayList<>();
                tmp.add(i);
                sumMap.put(curSum, tmp);
            }
        }
        sumMap.clear();
        return res;
    }
    public static void main(String args[])
    {
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
            ArraySumEqualToANumber ob = new ArraySumEqualToANumber();
            ArrayList<Pair>result = ob.findSubarraysWithGivenSum(a,sum);
            System.out.println(result.size());

            /*for(int i = 0; i < result.size();i++) {
                System.out.println(result.get(i).getLeft() + "      " + result.get(i).getRight());
            }*/
        }
    }
}

package com.company;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    public static boolean deg(int n){
        n= Math.abs(n);
        if(n==0)
            return false;
        if(n==1)
            return true;
        if(n%2==0){
            deg(n/2);
        }
        else
            return false;
        return true;
    }

    static class Item implements Comparable<Item>{
        public int cost;
        public int weight;

        public Item(int cost, int weight) {
            this.cost = cost;
            this.weight = weight;
        }
        @Override
        public int compareTo(Item o){
            double x = (double)cost/weight;
            double y = (double)o.cost/o.weight;
            return -Double.compare(x, y);
        }
    }

    static double foo(int W, Item[] items){
        double res = 0;
        for(int i = 0;i<items.length;i++){
            if(items[i].weight<=W){
                res+=items[i].cost;
                W-=items[i].weight;
            }
            else{
                double t = W-items[i].weight;
                res+=items[i].cost*(double)W/items[i].weight;
            }
        }
        return res;

    }

    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);
        int n = in.nextInt();
        int W = in.nextInt();
        Item[] items = new Item[n];
        for(int i = 0;i<n;i++)
            items[i] = new Item(in.nextInt(), in.nextInt());
        Arrays.sort(items);
        System.out.println(foo(W, items));
    }
}

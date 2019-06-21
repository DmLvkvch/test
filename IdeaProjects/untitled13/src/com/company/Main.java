package com.company;

import java.util.Scanner;

public class Main {

    public static int[] sort(int[] a){
        int[] res = new int[11

                ];
        for(int i = 0;i<a.length;i++){
            res[a[i]]++;
        }
        int[] ans = new int[a.length];
        int k = 0;
        for(int i = 0;i<res.length;i++){
            if(res[i]!=0){
                while(res[i]!=0) {
                    ans[k] = i;
                    res[i]--;
                    k++;
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n];
        for(int i = 0;i<n;i++){
            a[i] = in.nextInt();
        }
	        a = sort(a);
	        for(int i = 0;i<a.length;i++)
	            System.out.println(a[i]);

    }
}

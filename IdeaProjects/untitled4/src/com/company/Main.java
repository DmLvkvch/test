package com.company;
import java.util.Scanner;
public class Main {


    public static int Fib(int n, int m){
        int res = 0;
        int x = 1;
        int y = 1;
        if(n==0)
            return 0;
        if(n==1 || n==2){
            return 1;
        }
        for(int i = 2;i<n;i++){
            res = (x + y)%m;
            x = y%m;
            y = res%m;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        int x = in.nextInt();
        int[] arr = new int[6*x];
        arr[0] = 0;
        arr[1] = 1;
        int index = 0;
        for(int i = 2;i<=num;i++){
            arr[i] = Fib(i, x);
            if(arr[i]==0 && arr[i-1]==1){
                index = i;
                break;
            }
        }
        System.out.println(arr[x%(index)]);

    }
}

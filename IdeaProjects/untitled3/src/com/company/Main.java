package com.company;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Main {
    public static int[] merge(int[] a, int[] b){
        int[] res = new int[a.length+b.length];
        int i = 0, j = 0;
        for(int k = 0;k<res.length;k++){
            if(i == a.length){
                for(;j<b.length;j++) {
                    res[k++] = b[j];
                }
                return res;
            }
            if(j == b.length){
                for(;i<a.length;i++) {
                    res[k++] = a[i];
                }
                return res;
            }
            if(a[i]<b[j]){
                res[k] = a[i++];
            }
            else{
                res[k] = b[j++];
            }
        }
        return res;
    }

    public static int[] comp(int[] a){
        if(a.length==1)
            return a;
        else{
            if(a[0]<a[1])
                return a;
            else{
                int c = a[0];
                a[0] = a[1];
                a[1] = c;
                return a;
            }
        }
    }

    public static int[] sort(int[] a){
        int[] res = new int[a.length];
        int[] x = Arrays.copyOfRange(a, 0, a.length/2);
        int[] y = Arrays.copyOfRange(a, a.length/2, a.length);
        if(x.length<=2 && y.length<=2){
            x = comp(x);
            y = comp(y);
             res = merge(x, y);
             return res;
        }
        x = sort(x);
        y = sort(y);
        res = merge(x, y);
        return res;
    }

    public static int BS(int[] a, int key){
        int m = a.length/2;
        int index = -1;
        if(a.length==1){
            if(a[0]!=key)
                index = -1;
                return index;
        }
        if(key == a[m]) {
            return m;
        }
        if(key>a[m]) {
            int[] x = Arrays.copyOfRange(a, a.length/2, a.length);
            BS(x, key);
        }
        else{
            int[] x = Arrays.copyOfRange(a, 0, a.length/2);
            BS(x, key);
        }
        return index;
    }

    public static void main(String[] args) {
        int[] a = {1, 5, 7,6, 2, 2, 52, 6215, 251 ,5};
        a = sort(a);
        for(int i = 0;i<a.length;i++)
            System.out.print(a[i]+" ");
        System.out.println(BS(a, 1));
    }


}

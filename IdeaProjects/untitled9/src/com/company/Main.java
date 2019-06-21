package com.company;

import java.util.PriorityQueue;
import java.util.Vector;



public class Main {

    static boolean prime(int n){
        for(int i = 2;i<=n;i++){
            if(n%i == 0 && n!=i)
                return false;
        }
        return true;
    }

    static public String fact(int n){
        String res = new String();
        int[] q = new int[n+1];
        for(int i = 2;i<=n;i++){
            for(int j = 2;j<=i;j++){
                if(i%j == 0){
                    if(prime(j)==true) {
                        System.out.println("prime j: "+i+" "+j);
                        q[j]++;
                        i/=j;
                    }
                    else{
                        int t = i;
                        for(int k = 2;k<Math.sqrt(t);k++){
                            if(t%k==0 && t!=k)
                                q[k]++;
                        }
                        continue;
                    }
                }
            }
        }
        for(int i = 0;i< n+1;i++){
            if(q[i]!=0){
                res+=i+"^"+q[i]+"*";
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String s = fact(12);
        System.out.println(s);
    }
}

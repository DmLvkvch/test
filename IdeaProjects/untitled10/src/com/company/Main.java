package com.company;

public class Main {

    static String fact(int t){
        String res = new String();
        int n = t;
        int[] q = new int[(int)Math.sqrt(n)+1];
        boolean flaq = false;
        int k = (int)Math.sqrt(n)+1;
        for(int i = 2;i<=k;i++){
            if(n==1)
                break;
            while(n%i==0){
                q[i]++;
                n/=i;
            }
        }

        if(n!=t) {
            for (int i = 2; i < k; i++) {
                if (q[i] != 0) {
                    if (q[i] == 1) {
                        res += "(" + i + ")";

                    } else
                        res += "(" + i + "**" + q[i] + ")";
                }
            }
        }
        else
            return "("+n+")";
        return res;
    }

    public static void main(String[] args) {
	    int n = 933555431;
	    System.out.println(fact(n));

    }
}

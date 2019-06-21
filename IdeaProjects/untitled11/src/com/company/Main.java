package com.company;

public class Main {

    public static void main(String[] args) {
	    ComplexNumber x = new ComplexNumber(1, 1);
        ComplexNumber y = new ComplexNumber(1, 1);
        int t = x.hashCode();
        System.out.println(t);
	    System.out.println(x.equals(y));

    }
}

// Write a program to print number from increasing and crecresing order

import java.io.*;
import java.util.*;

public class PrintIncreDecr{
    public static void main(String[] args){
        Scanner snc = new Scanner(System.in);
        int n= snc.nextInt();
        pdi(n);
    }
    public static void pdi(int n){
        if(n<0){
            return;
        }
        System.out.println(n+" ");
        pdi(n-1);
        System.out.println(n);
    }
}
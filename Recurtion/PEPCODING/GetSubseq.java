// this question is similer like Subseq.java problem but in this problem we dont stare all the sub sequence in array
//  as memory limit exceed so we only print as the base case hits evry time

// SC : (n+1)*n where n+1 is size of recursiv e stack

import java.util.*;

public class GetSubseq{
    public static void printSS(String str, String ans){

        if(str.length()==0){
            System.out.println(ans);
            return;
        }
        // get first char
        char first = str.charAt(0);
        String rest = str.substring(1);

        printSS(rest,ans+first);
        printSS(rest,ans+"");
            }
    public static void main(String [] args){
        Scanner scn =new Scanner(System.in);
        String str = scn.next();
        printSS(str,"");
    }
}
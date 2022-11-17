// print permuatation
import java.util.*;

public class PrintPermutation{
    public static void printPermuatation(String str,String ans){
        if(str.length()==0){
            System.out.println(ans);
            return;
        }
        for(int i=0;i<str.length();i++){
            // take one by one charecter from string and pass remaining string to recursive function
            char ch = str.charAt(i);
            String remLeft = str.substring(0,i);
            String remRight= str.substring(i+1);
            String total= remLeft+remRight;
            printPermuatation(total,ans+ch);
        }
    }
    public static void main(String args []){
        Scanner scn = new Scanner(System.in);
        String str =  scn.next();
        printPermuatation(str,"");
    }
}
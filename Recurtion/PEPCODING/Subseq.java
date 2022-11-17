import java.util.*;
class Subseq{
    public static ArrayList<String> getSubseq(String str){
        // basecase for by using which next subseq get created
        if(str.length()==0){
            ArrayList<String> baseList = new ArrayList<>();
            baseList.add("");
            return baseList;
        }
        char first = str.charAt(0);
        String newStr = str.substring(1);
        ArrayList<String> rRes = getSubseq(newStr);

        ArrayList<String> Res = new ArrayList<>();

        for(int i=0;i<rRes.size();i++){
            Res.add(rRes.get(i));
        }
        for(int i=0;i<rRes.size();i++){
            Res.add(first+rRes.get(i));
        }
        return Res;
    }
    public static void main(String args[]){
        String str = "abc";
        ArrayList<String> list = getSubseq(str);
        System.out.println(list);
    }
}
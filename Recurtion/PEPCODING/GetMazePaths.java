
// https://www.youtube.com/watch?v=7i41gZLXe5k&list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&index=31

import java.util.*;
public class GetMazePaths{
    public static ArrayList<String> ReturnPaths(int sr,int sc,int dr,int dc){
        // base case 
        if(sc==dc && sr==dr){
            ArrayList<String> blist = new ArrayList<>();
            blist.add("");
            return blist;
        }
        ArrayList<String> hpaths = new ArrayList<>();
        ArrayList<String> vpaths = new ArrayList<>();
        // case handding for increment columns out off boundry 
        if(sc<dc){
        hpaths = ReturnPaths(sr,sc+1,dr,dc);
        }
        if(sr<dr){
        vpaths = ReturnPaths(sr+1,sc,dr,dc);
        }

// add h and v to previously comed paths
        ArrayList<String> paths = new ArrayList<>();
        for(String path : hpaths){
            paths.add("h" + path);
        }
        for(String path : vpaths){
            paths.add("v" + path);
        }
        return paths;
    }
    public static void main(String args []){
        Scanner scn = new Scanner(System.in);
        int r = scn.nextInt();
        int c = scn.nextInt();

        ArrayList<String> list= ReturnPaths(0,0,r-1,c-1);
        System.out.println(list);
    }
}
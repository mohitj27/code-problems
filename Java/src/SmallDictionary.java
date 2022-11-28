import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class SmallDictionary {
    static Scanner scn = new Scanner(System.in);
    static ArrayList<String> Res;
    public static void main(String[] args) {
        String str = scn.nextLine();
        Res = new ArrayList<String>();
        recDict(str,"",str);
        Collections.sort(Res);
        for(String res: Res){
            System.out.println(res);
        }

    }
    public static void recDict(String str,String result, String input){
        if(str.length() == 0){
            if(input.compareTo(result)>0) {
                Res.add(result);
//                System.out.println(result);
            }
            return;
        }
        for(int i =0; i < str.length();i++){
            if(str.charAt(i) <= str.charAt(0)){
                recDict(str.substring(0,i)+str.substring(i+1),result+str.charAt(i),input);
            }
        }
    }
}

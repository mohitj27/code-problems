import java.util.Scanner;

public class Replacepi {
    static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){

        String str = scn.nextLine();
        str = RecursiveReplacePi(str);
        System.out.println(str);

    }
    public static String RecursiveReplacePi(String str){
        if(str.length() == 0){
            return str;
        }
        if(str.charAt(0) == 'p' && str.length() >=2 && str.charAt(1) == 'i' ){
            return "3.14"+ RecursiveReplacePi(str.substring(2));
        }
        return str.charAt(0) + RecursiveReplacePi(str.substring(1));
    }
}

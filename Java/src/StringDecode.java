import java.util.Scanner;

public class StringDecode {
    static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        String str = scn.nextLine();
        StringBuilder result = new StringBuilder();
        for(int i =0; i < str.length();i++){
            if(str.charAt(i) >= 48 && str.charAt(i)<=57){
                int temp = (int)(str.charAt(i)) - 48;

                while( (temp)--!=0 )
                result.append(str.charAt(i-1));
            }
        }
        System.out.println(result);
    }
}

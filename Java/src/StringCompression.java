import java.util.Scanner;

public class StringCompression {
    static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        String str = scn.nextLine();
        int[] frq = new int[26];
        for(int i = 0; i < str.length(); i++){
            frq[str.charAt(i) - 'a']++;
            if(i!=0){
                if(str.charAt(i-1) != str.charAt(i)){
                    if(frq[str.charAt(i-1) - 'a']!=0){
                        System.out.print(str.charAt(i-1));
                        if(frq[str.charAt(i-1) - 'a']!=1)
                            System.out.print(frq[str.charAt(i-1) - 'a']);
                        frq[str.charAt(i-1)-'a'] = 0;
                    }
                }
            }

        }
          System.out.print(str.charAt(str.length()-1));
         if(frq[str.charAt(str.length()-1) - 'a']!=1){
             System.out.print(frq[str.charAt(str.length()-1) - 'a']);
         }
    }
}

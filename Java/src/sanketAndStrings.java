import java.util.Scanner;

public class sanketAndStrings {
    static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        int n = scn.nextInt();
        scn.nextLine();
        String str = scn.nextLine();
        int ansA = getResult(str,n,'a');
        int ansB = getResult(str,n,'b');
        int result = Math.max(ansA,ansB);
        System.out.println(result);


    }
    public static int getResult(String str,int n, char ch){
        int ans = 0;
        int left = 0;
        int right = 0;
        int count = 0;

        for(;right<str.length()-1;right++){
            if(str.charAt(right)!=ch) {
                count++;
            }
            if(count == n) break;
        }
        while(left < right){
            while(right < str.length()-1 && str.charAt(right+1)== ch ){
                right++;
            }
            int currLen = right-left+1;
            ans = Math.max(ans,currLen);
            if(str.charAt(left)!=ch && right<str.length()-1){
                right++;
            }
            left++;
        }


        return ans;

    }
}

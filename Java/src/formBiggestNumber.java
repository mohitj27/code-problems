import java.util.*;

public class formBiggestNumber {
    static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {

        int t = scn.nextInt();
        int n = scn.nextInt();
        int[] arr = new int[n];
        String[] kar = new String[n];
        for( int i =0; i < n; i++) {
            arr[i] = scn.nextInt();
            kar[i] = Integer.toString(arr[i]);
        }
        Arrays.sort(kar, new Comparator<String>(){
         @Override public int compare(String X, String Y){
             String XY = X + Y;

             String YX = Y + X;
             return XY.compareTo(YX) > 0 ? -1 : 1;
         }
        });

        StringBuilder sb = new StringBuilder();
        for(String s:kar) sb.append(s);

        System.out.println(sb.toString());


    }
}

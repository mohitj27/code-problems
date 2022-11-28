import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class SortLinear {

    static Scanner Scn = new Scanner(System.in);

    public static void main(String[] args) {
        int sz = Scn.nextInt();

        int[] arr = new int[sz];

        for(int i= 0; i < sz; i ++) {
            arr[i] = Scn.nextInt();
        }
        int l = 0;
        int m = 0;
        int h = sz-1;
         int temp = 0;
          while(m<=h){
              if(arr[m] == 0){
                  temp = arr[l];
                  arr[l] = arr[m];
                  arr[m] = temp;
                  l++;
                  m++;
              } else if(arr[m] == 1){
                  m++;
              } else {
                  temp = arr[m];
                  arr[m] = arr[h];
                  arr[h] = temp;
                  h--;
              }
          }

            for(int i = 0; i < sz; i++){
                System.out.println(arr[i]);
            }
    }

}

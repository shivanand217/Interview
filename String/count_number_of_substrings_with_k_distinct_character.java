import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class count_number_of_substrings_with_k_distinct_character {

    private static int[] hash = new int[256];
    private static int distinct = 0;
    private static int substrings = 0;
    private static ArrayList<String> a = new ArrayList<String>();

    public static void main(String args[]) throws IOException, NullPointerException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        String stt = "";

        String str = s[0];
        int k = Integer.parseInt(s[1]);

        for(int i=0; i < 256; i++) {
            hash[i]=0;
        }

        StringBuilder st = new StringBuilder("");

        for(int i=0; i < str.length(); i++) {
            /** clearing frequency count **/
            st.delete(0, st.length());
            for(int j=0; j < 256; j++){
                hash[j]=0;
            }
            distinct = 0;

            for(int j=i; j < str.length(); j++) {

                int asc = (int) str.charAt(j);
                st.append(str.charAt(j));

                if(hash[asc] == 0) {
                    distinct++;
                }

                hash[asc]++;

                /** if we have k distinct characters in this substring **/
                if(distinct == k) {
                    substrings++;
                    stt = st.toString();
                    a.add(stt);
                }
                if(distinct > k) {
                    break;
                }
            }
        }

        System.out.println("Number of substrings having "+ k +" distinct characters is "+substrings);
        for(String b: a) {
            System.out.println(b);
        }
    }

}

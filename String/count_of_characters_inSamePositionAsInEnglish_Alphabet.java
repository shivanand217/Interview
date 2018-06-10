import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class count_of_characters_inSamePositionAsInEnglish_Alphabet {

    private static int ans=0, pos=0;

    public static void main(String args[]) throws IOException, NullPointerException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        ArrayList<Character> a = new ArrayList<Character>();

        for(int i=0; i < s.length(); i++) {
            if(s.charAt(i)>='a' && s.charAt(i)<='z') {
                pos = s.codePointAt(i)-97;
                if(pos+1 == i+1) {
                    ans++;
                    a.add(s.charAt(i));
                }
            }
            if(s.charAt(i)>='A' && s.charAt(i)<='Z') {
                pos = s.codePointAt(i)-65;
                if(pos+1 == i+1) {
                    ans++;
                    a.add(s.charAt(i));
                }
            }
        }

        System.out.println(ans);
        for(Character p : a) {
            System.out.println(p);
        }
    }

}


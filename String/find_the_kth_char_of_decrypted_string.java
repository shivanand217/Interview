import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class find_the_kth_char_of_decrypted_string {

    private static int curr = 0,  find = 0, target = 0, old = 0, i = 0, _new;
    private static int count = 0, len = 0, len2 = 0;
    private static char ans = '!';

    public static void main(String args[]) throws IOException, NullPointerException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        len = s.length();
        StringBuilder s1 = new StringBuilder(s);
        StringBuilder s2 = new StringBuilder("");

        s = br.readLine();
        target = Integer.parseInt(s);

        while(i < s1.length()) {
            count=0;
            s2.delete(0, s2.length());
            if(s1.codePointAt(i)>=97 && s1.codePointAt(i)<= 122) {
                while(s1.codePointAt(i)>=97 && s1.codePointAt(i)<=122){
                    s2.append(s1.charAt(i));
                    i++;
                    if(i == len) {
                        break;
                    }
                }
                if(i == s1.length()) {
                    break;
                }
                if(s1.charAt(i) >= '1' && s1.charAt(i) <= '9') {
                    while(s1.charAt(i) >= '1' && s1.charAt(i) <= '9') {
                        count = count * 10 + Integer.parseInt(String.valueOf(s1.charAt(i)));
                        i++;
                        if(i == s1.length()){
                            break;
                        }
                    }
                }

                /** question logic **/
                /** length of current substring **/
                len2 = s2.length();
                _new = len2*count;

                old = curr;
                curr = curr + _new;
                if(curr >= target) {
                    /** then we have to find in current substring **/
                    find = target - old;

                    if(find <= len2) {
                        find--;
                        ans = s2.charAt(find);
                    } else {
                        find = find%len2;
                        if(find == 0) {
                            ans = s2.charAt(s2.length()-1);
                        } else {
                            find--;
                            ans = s2.charAt(find);
                        }
                    }
                    break;
                }
                // System.out.print(s2 + " " + count);
            }
                // System.out.println();
        }

        if(ans == '!') {
            System.out.println("No character at that position");
        } else {
            System.out.println(ans);
        }

    }
}

import java.io.BufferedReader ;
import java.io.IOException ;
import java.io.InputStreamReader ;
import java.io.BufferedWriter ;
import java.io.OutputStreamWriter ;
public class SumTwoNum {
    static BufferedWriter bw ;
    static BufferedReader br ;

    public static int repeatUntilDone(boolean isFirst) throws IOException{
        int num ;
        while(true) {
            try {
                if (isFirst) {
                    bw.write("첫 번째 숫자를 입력해주세요 : ");
                    bw.flush();
                } else {
                    bw.write("두 번째 숫자를 입력해주세요 : ");
                    bw.flush();
                }
                num = Integer.parseInt(br.readLine()) ;
                break ;
            } catch (NumberFormatException e) {
                bw.write("[입력 오류] : 숫자를 입력해주세요.\n");
            }
        }

        return num ;
    }

    public static void main(String[] args) throws IOException {

        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br = new BufferedReader((new InputStreamReader(System.in)));

        int A = repeatUntilDone(true);
        int B = repeatUntilDone(false);

        bw.write("결과 : " +  A+B);
        bw.flush();
        bw.close();
    }
}

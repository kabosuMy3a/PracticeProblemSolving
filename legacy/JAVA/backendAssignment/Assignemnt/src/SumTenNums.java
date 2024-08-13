import java.io.BufferedReader ;
import java.io.IOException ;
import java.io.InputStreamReader ;
import java.io.BufferedWriter ;
import java.io.OutputStreamWriter ;
public class SumTenNums {
    static BufferedWriter bw ; static BufferedReader br ;
    public static int repeatUntilDone(int order) throws IOException{
        int num ;
        while(true) {
            try {
                bw.write("숫자 ");
                bw.write(order + " : ");
                bw.flush();

                num = Integer.parseInt(br.readLine()) ;
                break ;
            } catch (NumberFormatException e) {
                bw.write("[입력 오류] : 숫자로 입력해주세요.\n");
            }
        }

        return num ;
    }

    public static void main(String[] args) throws IOException {

        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br = new BufferedReader((new InputStreamReader(System.in)));
        int sum = 0 ;
        for(int i = 1 ; i <= 10 ; i++) {
            sum += repeatUntilDone(i);
        }

        bw.write("결과 : " +  sum);
        bw.flush();
        bw.close();
    }
}

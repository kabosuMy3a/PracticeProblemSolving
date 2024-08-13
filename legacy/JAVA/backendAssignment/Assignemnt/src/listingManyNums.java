import java.io.BufferedReader ;
import java.io.IOException ;
import java.io.InputStreamReader ;
import java.io.BufferedWriter ;
import java.io.OutputStreamWriter ;
import java.util.ArrayList ;

public class listingManyNums {
    static BufferedWriter bw ; static BufferedReader br ;
    public static int repeatUntilDone(int order) throws IOException{
        int num ;
        while(true) {
            try {
                bw.write("숫자 "); bw.write(order + " : ");
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
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int order = 1 ;
        while(true){
            int num = repeatUntilDone(order);
            if(num == 0) break ;
            arr.add(num);
            order++ ;
        }

        bw.write("결과 : ");
        for(int i = 0 ; i < arr.size(); i++){
            bw.write(String.valueOf(arr.get(i)));
            if(i < arr.size() -1) bw.write(", ");
        }
        bw.flush();
        bw.close();
    }
}


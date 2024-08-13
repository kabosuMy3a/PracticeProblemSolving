import java.io.BufferedReader ;
import java.io.IOException ;
import java.io.InputStreamReader ;
import java.io.BufferedWriter ;
import java.io.OutputStreamWriter ;
import java.util.ArrayList ;
import java.util.Comparator ;

public class simpleCommunity {

    public static class Post {
        private String title ;
        private String content ;

        public String getContent() {
            return content;
        }

        public void setContent(String content) {
            this.content = content;
        }

        public String getTitle() {
            return title;
        }

        public void setTitle(String title) {
            this.title = title;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader((new InputStreamReader(System.in)));
        ArrayList<Post> posts = new ArrayList<Post>();

        while(true){
            bw.write("명령어) "); bw.flush();
            String command = br.readLine();
            if(command.equals("종료")){
                bw.write("프로그램을 종료합니다."); bw.flush();
                break;
            } else if(command.equals("등록")){
                Post p = new Post();
                bw.write("제목 : "); bw.flush();
                p.setTitle(br.readLine());
                bw.write( "내용 : "); bw.flush();
                p.setContent(br.readLine());
                posts.add(p);
                bw.write("[알림] " + posts.size()+ "번글이 등록되었습니다.\n"); bw.flush();

            } else if(command.equals("조회")){
                bw.write("몇 번글을 조회하시겠습니까? "); bw.flush();
                int no ;
                while(true){
                    try{
                        no = Integer.parseInt(br.readLine());
                        break;
                    } catch (NumberFormatException e){
                        bw.write("숫자로 입력해주세요.\n"); bw.flush();
                    }
                }
                if(no > posts.size()){
                    bw.write("현재 게시글 수는 "+ posts.size() + "개 입니다.\n"); bw.flush();
                } else {
                    bw.write(posts.get(no-1).getContent() + "\n");
                    bw.flush();
                }
            } else if(command.equals("목록")){
                int i = 1 ;
                for(Post p : posts){
                    bw.write(i + " / " + p.getTitle() + "\n");
                    bw.flush();
                    i++;
                }
            } else {
                bw.write("등록되지 않은 명령어입니다.\n"); bw.flush();
            }
        }
    }
}

interface Moveable{
    int move();
    int stop();
}

class Ball implements Moveable{
    int move(){
        System.out.println("공이 움직인다.");
        return 1 ;
    }
    int stop(){
        System.out.println("공이 멈춘다.");
        return 2; 
    }
}
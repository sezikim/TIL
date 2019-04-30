import processing.core.PApplet;
import processing.core.PImage;

import java.util.ArrayList;

public class Frame extends PApplet {
    public static final int WIDTH = 500;
    public static final int HEIGHT = 800;
    private static final int DDONG_NUM = 100;
    private static final int PDDONG_NUM = 20;
    private long start;
    private long end;

    ArrayList<Ddong> ddongList;
    ArrayList<Pddong> pddongList;
    Player player;
    PImage endImage;

    public static void main(String[] args) {
        PApplet.main("Frame");
    }

    public void settings() {
        start = System.currentTimeMillis();
        size(WIDTH, HEIGHT);
        player = new Player(this);
        Player.setLife(5);

        ddongList = new ArrayList<>();
        for (int i = 0; i < DDONG_NUM; ++i) {
            ddongList.add(new Ddong(this));
        }

        pddongList = new ArrayList<>();
        for (int i = 0; i < PDDONG_NUM; ++i) {
            pddongList.add(new Pddong(this));
        }
        endImage = loadImage("end.png");
    }

    public void setup() {
    }

    public void draw() {
        this.background(255);

        if (Player.getLife() > 0)  {
            for (Ddong ddong : ddongList) {
                ddong.move(this);
                ddong.display(this);
                if (isCollision(player, ddong)) {
                    ddong.getPointD().setX((float) (Math.random() * Frame.WIDTH));
                    ddong.getPointD().setY((float) (Math.random() * (-Frame.HEIGHT * 10)));
                    Player.setLife(Player.getLife() - 1);
                }
            }

            for (Pddong pDdong : pddongList) {
                pDdong.move(this);
                pDdong.display(this);
                if (isCollision(player, pDdong)) {
                    pDdong.getPointD().setX((float) (Math.random() * Frame.WIDTH));
                    pDdong.getPointD().setY((float) (Math.random() * (-Frame.HEIGHT * 20)));
                    Player.setLife(Player.getLife() - 2);
                }
            }
            player.display(this);
            player.move(this);
            end = System.currentTimeMillis();
            textSize(32);
            text(String.valueOf((end-start) / 1000), 10, 30);
            fill(0, 100, 150);
        } else {
            image(endImage, 0, 0, WIDTH, HEIGHT);
            textSize(50);
            text("Score : " + String.valueOf((end-start)/1000), WIDTH/4, HEIGHT/10);
            fill(255, 0, 0);

            textSize(30);
            text("Press ENTER to continue",WIDTH/10, HEIGHT/5);
            fill(255,0,0);

            if(key == ENTER) {
                settings();
            }
        }
    }

    public static boolean isCollision(Player player, Ddong ddong) {
        if (Point2.getDistance(player.getPointP(), ddong.getPointD()) < ddong.getHeight() * Math.sqrt(2) / 2) {
            return true;
        } else {
            return false;
        }
    }

    public static boolean isCollision(Player player, Pddong pDdong) {
        if (Point2.getDistance(player.getPointP(), pDdong.getPointD()) < pDdong.getHeight() * Math.sqrt(2) / 2) {
            return true;
        } else {
            return false;
        }
    }
}

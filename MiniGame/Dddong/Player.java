import processing.core.PApplet;
import processing.core.PImage;

public class Player {
    private Point2 pointP;
    private static int life = 5;
    private static int skill = 2;
    private static final int WIDTH = 30;
    private static final int HEIGHT = 30;
    private final PImage playerImage;
    private final PImage lifeImage;
    private final PImage skillImage;

    Player(PApplet p) {
        pointP = new Point2(Frame.WIDTH / 2 - WIDTH / 2, Frame.HEIGHT - HEIGHT / 2);
        playerImage = p.loadImage("player.png");
        lifeImage = p.loadImage("life.png");
        skillImage = p.loadImage("skill.png");
    }

    public void display(PApplet p) {
        p.image(playerImage, pointP.getX() - WIDTH / 2, pointP.getY() - HEIGHT / 2, WIDTH, HEIGHT);
        for (int i = 1; i <= life; i++) {
            p.image(lifeImage, Frame.WIDTH - 40 * i, 0, 40, 40);
        }
        for (int i = 1; i <= skill; i++) {
            p.image(skillImage, Frame.WIDTH - 40 * i, HEIGHT, 40, 40);
        }
       if (p.keyPressed) {
            if (p.key == p.CODED) {
                if (p.keyCode == p.UP) {
                    if (skill > 0) {
                        p.background(0,0,0);
                        p.image(skillImage, 0, 0, Frame.WIDTH, Frame.HEIGHT);
                        skill--;
                        p.keyReleased();
                    }
                }
            }
        }
    }

    public void move(PApplet p) {
        keyPressed(p);
    }

    public void keyPressed(PApplet p) {
        if (p.key == p.CODED) {
            if (p.keyCode == p.LEFT) {
                pointP.setX(pointP.getX() - 5);
                if (pointP.getX() + WIDTH / 2 < 0) {
                    pointP.setX(Frame.WIDTH);
                }
            } else if (p.keyCode == p.RIGHT) {
                pointP.setX(pointP.getX() + 5);
                if (pointP.getX() > Frame.WIDTH) {
                    pointP.setX(0 - WIDTH / 2);
                }
            }
        }
    }

    public static int getLife() {
        return life;
    }

    public static int getSkill() {
        return skill;
    }

    public Point2 getPointP() {
        return pointP;
    }

    public static int getWidth() {
        return WIDTH;
    }

    public static int getHeight() {
        return HEIGHT;
    }

    public static void setLife(int life) {
        Player.life = life;
    }
}

import processing.core.PApplet;
import processing.core.PImage;

public class Ddong {
    private Point2 pointD;
    private final float speed;
    private static final int WIDTH = 35;
    private static final int HEIGHT = 35;
    private final PImage ddongImage;

    public Ddong(PApplet p) {
        pointD = new Point2((float) (Math.random() * Frame.WIDTH),
                (float) (Math.random() * (-Frame.HEIGHT * 10)));
        speed = p.random(5);
        ddongImage = p.loadImage("ddong.png");
    }

    public void display(PApplet p) {
        p.image(ddongImage, pointD.getX() - WIDTH / 2, pointD.getY() - HEIGHT / 2, WIDTH, HEIGHT);
    }

    public void move(PApplet p) {
        pointD.setY(pointD.getY() + speed + p.millis() / 10000);
        if (pointD.getY() - HEIGHT / 2 > Frame.HEIGHT) {
            pointD.setX((float) (Math.random() * Frame.WIDTH));
            pointD.setY((float) (Math.random() * (-Frame.HEIGHT * 10)));
        }
        keyPressed(p);
    }

    public void keyPressed(PApplet p) {
        if (p.keyPressed) {
            if (p.key == p.CODED) {
                if (p.keyCode == p.UP) {
                    if (Player.getSkill() > 0) {
                        pointD.setX((float) (Math.random() * Frame.WIDTH));
                        pointD.setY((float) (Math.random() * (-Frame.HEIGHT * 10)));
                    }
                }
            }
        }
    }

    public Point2 getPointD() {
        return pointD;
    }

    public int getWIDTH() {
        return WIDTH;
    }

    public int getHeight() {
        return HEIGHT;
    }

}

import processing.core.PApplet;
import processing.core.PImage;

public class Pddong {
    private Point2 pointD;
    private final float speed;
    private static final int WIDTH = 25;
    private static final int HEIGHT = 25;
    private final PImage pddongImage;

    public Pddong(PApplet p) {
        pointD = new Point2((float) (Math.random() * Frame.WIDTH),
                (float) (Math.random() * (-Frame.HEIGHT * 30)));
        speed = 5;
        pddongImage = p.loadImage("Pddong.png");
    }

    public void display(PApplet p) {
        p.image(pddongImage, pointD.getX() - WIDTH/2, pointD.getY() - HEIGHT/2, WIDTH, HEIGHT);

    }

    public void move(PApplet p) {
        pointD.setY(pointD.getY() + speed);
        if (pointD.getY() - 20 > Frame.HEIGHT) {
            pointD.setX((float) (Math.random() * Frame.WIDTH));
            pointD.setY((float) (Math.random() * (-Frame.HEIGHT * 30)));
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

    public int getWidth() {
        return WIDTH;
    }

    public int getHeight() {
        return HEIGHT;
    }
}

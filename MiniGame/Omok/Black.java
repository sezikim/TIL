import processing.core.PApplet;

public class Black {
    private int[][] black;
    private static final int WIDTH = 30;
    private static final int HEIGHT = 30;

    Black() {
        black = new int[16][16];
    }

    public void display(PApplet p) {
        int i, j;
        for (i = 0; i < 16; ++i) {
            for (j = 0; j < 16; ++j) {
                if (black[i][j] == 1) {
                    p.fill(0);
                    p.ellipse(Board.getSQUARE() / 2 + Board.getSQUARE() * j,
                            Board.getSQUARE() / 2 + Board.getSQUARE() * i,
                            WIDTH, HEIGHT);
                }
            }
        }
    }

    public void setBlack(int x, int y) {
        black[y][x] = 1;
    }
}


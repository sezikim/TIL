import processing.core.PApplet;

public class White {
    private int[][] white;
    private static final int WIDTH = 30;
    private static final int HEIGHT = 30;

    White() {
        white = new int[16][16];
    }

    public void display(PApplet p) {
        int i, j;
        for (i = 0; i < 16; ++i) {
            for (j = 0; j < 16; ++j) {
                if (white[i][j] == 1) {
                    p.fill(255);
                    p.ellipse(Board.getSQUARE()/2 + Board.getSQUARE() * j,
                            Board.getSQUARE()/2 + Board.getSQUARE() * i,
                            WIDTH, HEIGHT);
                }
            }
        }
    }
    public void setWhite(int x, int y) {
        white[y][x] = 1;
    }
}


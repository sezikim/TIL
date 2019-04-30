import processing.core.PApplet;

public class Board extends PApplet {
    private Black black;
    private White white;
    private int[][] board;
    private boolean flag = true;
    private int winner;

    private static final int WIDTH = 640;
    private static final int HEIGHT = 640;
    private static final int SQUARE = 40;
    private static final int NONE = 0;
    private static final int BLACK = 1;
    private static final int WHITE = 2;

    public static void main(String[] args) {
        PApplet.main("Board");
    }

    public void settings() {
        size(WIDTH, HEIGHT);
        black = new Black();
        white = new White();
        board = new int[16][16];
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                board[i][j] = NONE;
            }
        }
        winner = NONE;
    }

    public void draw() {
        background(218, 165, 32);
        int i, j;
        for (i = 0; i < 16; ++i) {
            line(SQUARE / 2, SQUARE / 2 + SQUARE * i, WIDTH - SQUARE / 2, SQUARE / 2 + SQUARE * i);
        }
        for (j = 0; j < 16; ++j) {
            line(SQUARE / 2 + SQUARE * j, SQUARE / 2, SQUARE / 2 + SQUARE * j, HEIGHT - SQUARE / 2);
        }
        fill(0);
        if (inRange(mouseX, mouseY)) {
            cursor(HAND);
        } else {
            cursor(ARROW);
        }

        black.display(this);
        white.display(this);
        if (winner != 0) {
            switch (winner) {
                case BLACK:
                    textSize(50);
                    fill(0, 0, 0);
                    text("BLACK WIN", WIDTH / 3, HEIGHT / 4);
                    break;
                case WHITE:
                    textSize(50);
                    text("WHITE WIN", WIDTH / 3, HEIGHT / 4);
                    break;
            }
        }

    }

    public void mouseClicked() {
        int x = mouseX / SQUARE;
        int y = mouseY / SQUARE;
        if (flag) {
            if (inRange(mouseX, mouseY)) {
                if (board[y][x] == NONE
                        && !isForbidden(x, y)) {
                    board[y][x] = BLACK;
                    black.setBlack(x, y);
                    flag = false;
                    if (blackWin(x, y)) {
                        winner = BLACK;
                    }
                }
            }
        } else {
            if (inRange(mouseX, mouseY)) {
                if (board[y][x] == NONE
                        && !isForbidden(x, y)) {
                    board[y][x] = WHITE;
                    white.setWhite(x, y);
                    flag = true;
                    if (whiteWin(x, y)) {
                        winner = WHITE;
                    }
                }
            }
        }
    }

    public boolean isForbidden(int x, int y) {
        return false;
    }

    public boolean whiteWin(int x, int y) {
        int len1 = 0;
        int len2 = 0;
        int len3 = 0;
        int len4 = 0;

        for (int i = 1; i < 5; ++i) {
            if (inBoard(x - i, y - i) && board[y - i][x - i] == WHITE) len1++;
            if (inBoard(x + i, y + i) && board[y + i][x + i] == WHITE) len1++;
            if (inBoard(x, y - i) && board[y - i][x] == WHITE) len2++;
            if (inBoard(x, y + i) && board[y + i][x] == WHITE) len2++;
            if (inBoard(x + i, y - i) && board[y - i][x + i] == WHITE) len3++;
            if (inBoard(x - i, y + i) && board[y + i][x - i] == WHITE) len3++;
            if (inBoard(x + i, y) && board[y][x + i] == WHITE) len4++;
            if (inBoard(x - i, y) && board[y][x - i] == WHITE) len4++;
        }
        if (len1 > 3 || len2 > 3 || len3 > 3 || len4 > 3) return true;
        else {
            return false;
        }
    }


    public boolean blackWin(int x, int y) {
        int len1 = 0;
        int len2 = 0;
        int len3 = 0;
        int len4 = 0;

        for (int i = 1; i < 5; ++i) {
            if (inBoard(x - i, y - i) && board[y - i][x - i] == BLACK) len1++;
            if (inBoard(x + i, y + i) && board[y + i][x + i] == BLACK) len1++;
            if (inBoard(x, y - i) && board[y - i][x] == BLACK) len2++;
            if (inBoard(x, y + i) && board[y + i][x] == BLACK) len2++;
            if (inBoard(x + i, y - i) && board[y - i][x + i] == BLACK) len3++;
            if (inBoard(x - i, y + i) && board[y + i][x - i] == BLACK) len3++;
            if (inBoard(x + i, y) && board[y][x + i] == BLACK) len4++;
            if (inBoard(x - i, y) && board[y][x - i] == BLACK) len4++;
        }
        if (len1 > 3 || len2 > 3 || len3 > 3 || len4 > 3) return true;
        else {
            return false;
        }
    }

    public boolean inBoard(int x, int y) {
        return (x >= 0 && x < 16) && (y >= 0 && y < 16);
    }

    public boolean inRange(int x, int y) {
        return ((x - SQUARE / 2) % SQUARE < 5 || (x - SQUARE / 2) % SQUARE > SQUARE - 5)
                && ((y - SQUARE / 2) % SQUARE < 5 || (y - SQUARE / 2) % SQUARE > SQUARE - 5);
    }

    public static int getSQUARE() {
        return SQUARE;
    }
}


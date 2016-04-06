class Board {
    private static final int defaultsize = 10;
    private String[][] data;
    private int w;
    private int h;

    public Board() {
        w = defaultsize;
        h = defaultsize;
        data = new String[h][w];
    }

    public Board(int _w, int _h) {
        w = _w;
        h = _h;
        data = new String[h][w];
    }

    public int GetW() {
        return w;
    }

    public int GetH() {
        return h;
    }

    public String GetEl(int _h, int _w) {
        return data[_h][_w];
    }

    public void SetEl(char c, int _h, int _w) {
        data[_h][_w] += c;
    }

    public void DelEl(char c, int _h, int _w) {
        StringBuilder sb = new StringBuilder(data[_h][_w]);
        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) == c) {
                sb.deleteCharAt(i);
                break;
            }
        }
        data[_h][_w] = sb.toString();
    }

    public void PrintBoard() {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (data[j][i].length() > 0)
                    System.out.print(data[j][i].charAt(0));
                else
                    System.out.print(" ");
            }
            System.out.println();
        }
    }

    public boolean isEmpty() {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (data[i][j].length() > 0)
                    return false;
            }
        }
        return true;
    }
}
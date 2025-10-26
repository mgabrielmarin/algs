import java.awt.Graphics;
import java.awt.Color;
import java.awt.Canvas;
import javax.swing.JFrame;

public class life {
    public static void main(String[] args) {
        String title = "Conway's Game of Life";
        Conway game = new Conway();
        JFrame frame = new JFrame(title);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.add(game.grid);
        frame.pack();
        frame.setVisible(true);
        game.mainloop();
    }

    public static class Cell {
        private final int x;
        private final int y;
        private final int size;
        private int state;

        public Cell(int x, int y, int size) {
            this.x = x;
            this.y = y;
            this.size = size;
        }

        public static final Color[] COLORS = {Color.WHITE, Color.BLACK};

        public void draw(Graphics g) {
            g.setColor(COLORS[state]);
            g.fillRect(x+1, y+1, size-1, size-1);
            g.setColor(Color.LIGHT_GRAY);
            g.drawRect(x, y, size, size);
        }

        public boolean isOff() {
            return state == 0;
        }

        public boolean isOn() {
            return state == 1;
        }

        public void turnOff() {
            state = 0;
        }

        public void turnOn() {
            state = 1;
        }
    }

    public static class GridCanvas extends Canvas {
        private Cell[][] array;

        public GridCanvas(int rows, int cols, int size) {
            array = new Cell[rows][cols];
            for (int r = 0; r < rows; ++r) {
                int y = r * size;
                for (int c = 0; c < cols; ++c) {
                    int x = c * size;
                    array[r][c] = new Cell(x, y, size);
                }
            }
            setSize(cols * size, rows * size);
        }

        public void draw(Graphics g) {
            for (Cell[] row : array) {
                for (Cell cell : row) {
                    cell.draw(g);
                }
            }
        }

        public void paint(Graphics g) {
            draw(g);
        }

        public int numRows() {
            return array.length;
        }

        public int numCols() {
            return array[0].length;
        }

        public Cell getCell(int r, int c) {
            return array[r][c];
        }

        public void turnOn(int r, int c) {
            array[r][c].turnOn();
        }

        public int test(int r, int c) {
            try {
                if (array[r][c].isOn()) {
                    return 1;
                }
            } catch (ArrayIndexOutOfBoundsException e) {

            }
            return 0;
        }
    }

    public static class Conway {
        private GridCanvas grid;

        public Conway() {
            grid = new GridCanvas(5, 10, 20);
            grid.turnOn(2,1);
            grid.turnOn(2,2);
            grid.turnOn(2,3);
            grid.turnOn(1,7);
            grid.turnOn(2,7);
            grid.turnOn(3,7);
        }
        private void mainloop() {
            while (true) {
                this.update();
                grid.repaint();
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    // do nothing
                }
            }
        }
        private int countAlive(int r, int c) {
            int count = 0;
            count += grid.test(r - 1, c - 1);
            count += grid.test(r - 1, c);
            count += grid.test(r - 1, c + 1);
            count += grid.test(r, c - 1);
            count += grid.test(r, c + 1);
            count += grid.test(r + 1, c - 1);
            count += grid.test(r + 1, c);
            count += grid.test(r + 1, c + 1);
            return count;
        }
        public void update() {
            int[][] counts = countNeighbors();
            updateGrid(counts);
        }

        private int[][] countNeighbors() {
            int rows = grid.numRows();
            int cols = grid.numCols();

            int[][] counts = new int[rows][cols];
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    counts[r][c] = countAlive(r, c);
                }
            }
            return counts;
        }
        private void updateGrid(int[][] counts) {
            int rows = grid.numRows();
            int cols = grid.numCols();

            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    Cell cell = grid.getCell(r, c);
                    updateCell(cell, counts[r][c]);
                }
            }
        }
        private static void updateCell(Cell cell, int count) {
            if (cell.isOn()) {
                if (count < 2 || count > 3) {
                    cell.turnOff();
                }
            } else {
                if (count == 3) {
                    cell.turnOn();
                }
            }
        }
    }
}

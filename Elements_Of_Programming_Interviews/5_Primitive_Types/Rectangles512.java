public class Rectangles512 {
    private static class Point {
        private int x;
        private int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "(" + x + "," + y + ")";
        }
    }

    private static class Rectangle {
        private Point lowLeft;
        private int width;
        private int height;

        public Rectangle(Point lowLeft, int width, int height) {
            this.lowLeft = lowLeft;
            this.width = width;
            this.height = height;
        }

        public String toString() {
            return "[" + lowLeft.toString() + "," + width + "," + height + "]";
        }
    }

    public Rectangle intersect(Rectangle r, Rectangle s) {
        if (s.lowLeft.x < r.lowLeft.x) {
            return intersect(s, r);
        }

        // if lowLeft of s in r
        if (s.lowLeft.x < r.lowLeft.x + r.width && 
                (s.lowLeft.y >= r.lowLeft.y && s.lowLeft.y < r.lowLeft.y + r.height)) {
            Point lowLeft = s.lowLeft;
            int h1 = s.height;
            int h2 = r.lowLeft.y + r.height - lowLeft.y;
            int height = h1 <= h2 ? h1 : h2;
            int w1 = s.width;
            int w2 = r.lowLeft.x + r.width - lowLeft.x;
            int width = w1 <= w2 ? w1 : w2;
            return new Rectangle(lowLeft, width, height);
        } else if (s.lowLeft.x < r.lowLeft.x + r.width &&
                (s.lowLeft.y + s.height >= r.lowLeft.y && s.lowLeft.y + s.height < r.lowLeft.y + r.height)) { // if topLeft of s in r
            Point topLeft = new Point(s.lowLeft.x, s.lowLeft.y + s.height);
            int h1 = s.height;
            int h2 = topLeft.y - r.lowLeft.y;
            int height = h1 <= h2 ? h1 : h2;
            int w1 = s.width;
            int w2 = r.lowLeft.x + r.width - topLeft.x;
            int width = w1 <= w2 ? w1 : w2;
            return new Rectangle(new Point(topLeft.x, topLeft.y - height), width, height);
        } else if (s.lowLeft.x < r.lowLeft.x + r.width &&
                (s.lowLeft.y < r.lowLeft.y && s.lowLeft.y + s.height > r.lowLeft.y + r.height)) {
            Point lowLeft = new Point(s.lowLeft.x, r.lowLeft.y);
            int height = r.height;
            int w1 = s.width;
            int w2 = r.lowLeft.x + r.width - s.lowLeft.x;
            int width = w1 <= w2 ? w1 : w2;
            return new Rectangle(lowLeft, width, height);
        } else { // no intersection
            return null;
        }
    }

    public static void main(String[] args) {
        Rectangles512 rect = new Rectangles512();

        Rectangle r1 = new Rectangle(new Point(1, 1), 3, 4);
        Rectangle s1 = new Rectangle(new Point(2, 3), 1, 1);
        System.out.println(r1 + "," + s1);
        System.out.println(rect.intersect(r1, s1) + "\n");

        Rectangle r2 = new Rectangle(new Point(2, 3), 1, 1);
        Rectangle s2 = new Rectangle(new Point(1, 1), 3, 4);
        System.out.println(r2 + "," + s2);
        System.out.println(rect.intersect(r2, s2) + "\n");

        Rectangle r3 = new Rectangle(new Point(1, 1), 3, 4);
        Rectangle s3 = new Rectangle(new Point(2, 0), 2, 2);
        System.out.println(r3 + "," + s3);
        System.out.println(rect.intersect(r3, s3) + "\n");

        Rectangle r4 = new Rectangle(new Point(1, 1), 3, 4);
        Rectangle s4 = new Rectangle(new Point(2, 0), 6, 6);
        System.out.println(r4 + "," + s4);
        System.out.println(rect.intersect(r4, s4) + "\n");

        Rectangle r5 = new Rectangle(new Point(1, 1), 3, 4);
        Rectangle s5 = new Rectangle(new Point(5, 0), 2, 2);
        System.out.println(r5 + "," + s5);
        System.out.println(rect.intersect(r5, s5) + "\n");
    }
}

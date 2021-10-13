import java.util.ArrayList;

public class Wave {

    private ArrayList<Shape> shapes;

    public Wave() {
        shapes = new ArrayList<>();
    }

    public void add(Shape shape)
    {
        shapes.add(shape);
    }

    public final void print() {
        for (Shape ss : shapes)
            ss.print();
    }
};

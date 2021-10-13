import java.io.*;

public abstract class Shape {

    private final int m_size;
    private final Pair<Integer,Integer> m_center;

    public Shape(Pair<Integer,Integer> center, int size) {
        this.m_center = center;
        this.m_size = size;
    }

    public final int getSize() {
        return m_size;
    }

    public final Pair<Integer, Integer> getCenter() {
        return m_center;
    }

    public abstract void print();
}

class Triangle extends Shape{

    public Triangle(Pair<Integer,Integer> center, int size) {
        super(center, size);
    }

    @Override
    public void print() {
        System.out.println("Triangle " + super.getCenter().first + ", " + this.getCenter().second + ", " + super.getSize() );
    }
}

class Square extends Shape{

    public Square(Pair<Integer,Integer> center, int size) {
        super(center, size);
    }

    @Override
    public void print() {
        System.out.println("Square " + super.getCenter().first + ", " + this.getCenter().second + " , " + super.getSize() );
    }
}

class Circle extends Shape{

    public Circle(Pair<Integer,Integer> center, int size) {
        super(center, size);
    }

    @Override
    public void print() {
        System.out.println("Circle " + super.getCenter().first + ", " + this.getCenter().second + " , " + super.getSize() );
    }
}



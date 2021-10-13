
public abstract class Creator {

    abstract public Shape factoryMethod(Pair<Integer,Integer> center, int size);

    public Wave makeWave(){

        Wave result= new Wave();
        result.add(factoryMethod(new Pair<Integer, Integer>(0,0),1));
        result.add(factoryMethod(new Pair<>(0,0),2));
        result.add(factoryMethod(new Pair<>(0,0),3));
        return result;
    }
}

class CircleWaveCreator extends Creator {

    @Override
    public Shape factoryMethod(Pair<Integer, Integer> center, int size) {
        return new Circle(center,size);
    }
}

class TriangleWaveCreator extends Creator {

    @Override
    public Shape factoryMethod(Pair<Integer, Integer> center, int size) {
        return new Triangle(center,size);
    }
}

class SquareWaveCreator extends Creator {

    @Override
    public Shape factoryMethod(Pair<Integer, Integer> center, int size) {
        return new Square(center,size);
    }
}
public class Main {

    public static void main(String[] args)
    {
        Client CircleClient = new Client(new CircleWaveCreator());
        Wave waveCircle = CircleClient.makeWave();
        waveCircle.print();
        System.out.println();

        Client TriangleClient = new Client(new TriangleWaveCreator());
        Wave waveTriangle = TriangleClient.makeWave();
        waveTriangle.print();
        System.out.println();

        Client SquareClient = new Client(new SquareWaveCreator());
        Wave squareWave = SquareClient.makeWave();
        squareWave.print();
    }
}

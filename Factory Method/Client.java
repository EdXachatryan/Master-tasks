public class Client {

    private Creator m_Creator;

    Client(Creator creator) {
        m_Creator = creator;
    }

    public Wave makeWave() {
        return m_Creator.makeWave();
    }

}

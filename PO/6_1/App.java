public class App 
{
    public static void main(String[] args) throws Exception 
    {
        bufor<String> box = new bufor<String>(17);
        Thread P = new Thread(new producent(box, 20));
        Thread K = new Thread(new konsument(box, 20));

        P.start();
        K.start();
    }
}

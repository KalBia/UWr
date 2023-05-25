public class App 
{
    public static void main(String[] args) throws Exception 
    {
        ListElem[] array = {new OnePair(), new Flush(), 
                            new OnePair(), new ThreeOfKind(), 
                            new FourOfKind(), new OnePair(), 
                            new ThreeOfKind()};
        // sorted: OnePair, OnePair, OnePair, ThreeOfKind
                // ThreeOfKind, Flush, FourOfKind

        mergeSort sort = new mergeSort(array, 0, array.length-1);
        Thread sort_process = new Thread(sort);

        try
        {
            sort_process.start();
            sort_process.join();
        }
        catch (InterruptedException e)
        {
            Thread.currentThread().interrupt();
            System.err.println("Thread (sort) interrupted.");
        }

        System.out.println("Sorted: ");
        for (int i = 0; i < array.length; i++)
            System.out.println(array[i]);
    }
}

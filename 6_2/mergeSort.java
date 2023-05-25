public class mergeSort implements Runnable
{
    ListElem[] array;
    int begin_index;
    int end_index;

    public mergeSort(ListElem[] a, int bi, int ei)
    {
        array = a;
        begin_index = bi;
        end_index = ei;
    }
    
    private void merge() // to nam zlaczy rozdzielane na pol tablice w tym kroku
    {
        // Find middle index of array
        int mid_index = (begin_index + end_index)/2;

        // Create temp array
        ListElem[] temp = new ListElem[array.length];

        // Copy data to temp array
        for (int i = begin_index; i <= end_index; i++)
            temp[i] = array[i];
        
        // Merge the temp arrays
 
        // Initial indexes of first and second subarrays
        int ind1 = begin_index;
        int ind2 = mid_index + 1;
 
        // Initial index of merged subarray array
        int indM = begin_index;
        while (ind1 <= mid_index && ind2 <= end_index) 
        {
            if ( (temp[ind1].compareTo(temp[ind2])) <= 0 ) 
            {
                array[indM] = temp[ind1];
                ind1++;
            }
            else 
            {
                array[indM] = temp[ind2];
                ind2++;
            }
            indM++;
        }
 
        /* Copy remaining elements of L[] if any */
        while (ind1 <= mid_index) 
        {
            array[indM] = temp[ind1];
            ind1++;
            indM++;
        }
 
        /* Copy remaining elements of R[] if any */
        while (ind2 <= end_index) 
        {
            array[indM] = temp[ind2];
            ind2++;
            indM++;
        }
    }

    public void run()
    {
        if (begin_index < end_index)
        {
            int mid_index = (begin_index + end_index)/2;
            mergeSort LeftArray = new mergeSort(array, begin_index, mid_index);
            mergeSort RightArray = new mergeSort(array, mid_index+1, end_index);

            Thread LeftSort = new Thread(LeftArray);
            Thread RightSort = new Thread(RightArray);

            LeftSort.start();
            RightSort.start();

            try 
            {
                LeftSort.join();
            }
            catch (InterruptedException e) 
            {
                Thread.currentThread().interrupt();
                System.err.println("Thread (left) interrupted.");
            }

            try 
            {
                RightSort.join();
            }
            catch (InterruptedException e) 
            {
                Thread.currentThread().interrupt();
                System.err.println("Thread (right) interrupted.");
            }

            merge();
        }
    }
}

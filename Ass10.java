import java.util.Arrays;
import java.util.Scanner;
public class Shellsort
{
    void shellSort(int array[], int n)
    {
        for (int interval = n / 2; interval > 0; interval /= 2)
        {
            for (int i = interval; i < n; i += 1)
            {
                int temp = array[i];
                int j;
                for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
                {
                    array[j] = array[j - interval];
                }
                array[j] = temp;
            }
        }
    }
public static void main(String args[])
{
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter the size of the array: ");
    int arr_size = 0;
    if (sc.hasNextInt())
    {
        arr_size = sc.nextInt();
    }
    int[] arr = new int[arr_size];
    System.out.println("Enter the elements of the array: ");
    for (int i = 0; i < arr_size; i++)
    {
        if (sc.hasNextInt())
        {
            arr[i] = sc.nextInt();
        }
    }
    Shellsort ss = new Shellsort();
    ss.shellSort(arr, arr_size);
    System.out.println("Sorted Array in Ascending Order: ");
    System.out.println("The elements of the array are: ");
    for (int i = 0; i < arr_size; i++)
    {
        System.out.print(arr[i] + " ");
    }
    sc.close();
    }
}


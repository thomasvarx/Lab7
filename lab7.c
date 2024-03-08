#include <stdio.h>
#include <string.h>
void slection_sort(int arr[], int n, int swaps[])
{
    int min_index;
    for (int i = 0; i < n-2; i++) 
    {
        
        min_index = i;
        for (int j = i+1 ; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swaps[i]++;   
        }
    }   
}
//Bubble sort
void bubble_sort(int arr[], int n, int swaps[])
{
    for(int k = 0; k < n - 1; k++)
    {   
        for (int i = 0; i < n - 1 - k; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                swaps[i]++;
            }
        }
    }
}

void swap_print(int arr[], int n, int swaps[]){
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d: # of times %d is swapped\n", swaps[i], arr[i]);
        total += swaps[i];
    }
    printf("total # of swaps: %d\n", total/2);
}


int main()
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int n = sizeof(array1)/sizeof(array1[0]);

    int bubble_swap_array1_count[n];
    int bubble_swap_array2_count[n];
    int selection_swap_array1_count[n];
    int selection_swap_array2_count[n];

    for (int i = 0; i < n; i++)
    {
        bubble_swap_array1_count[i] = 0;
        bubble_swap_array2_count[i] = 0;
        selection_swap_array1_count[i] = 0;
        selection_swap_array2_count[i] = 0;
        
    }
    

    int original_array1[n];
    int original_array2[n];
    for (int i = 0; i < n; i++)
    {
        original_array1[i] = array1[i];
        original_array2[i] = array2[i];
    }
    
    bubble_sort(array1, n, bubble_swap_array1_count);
    swap_print(array1, n, bubble_swap_array1_count);
    printf("\n");

    bubble_sort(array2, n, bubble_swap_array2_count);
    swap_print(array2, n, bubble_swap_array2_count);
    printf("\n");
    
    slection_sort(original_array1, n, selection_swap_array1_count);
    swap_print(original_array1, n, selection_swap_array1_count);
    printf("\n");
    
    slection_sort(original_array2, n, selection_swap_array2_count);
    swap_print(original_array2, n, selection_swap_array2_count);

    return 0;
}
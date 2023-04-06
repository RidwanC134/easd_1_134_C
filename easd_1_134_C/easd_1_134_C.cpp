// 1. Algorithma dibutuhkan untuk menyelesaikan suatu masalah karena algorithma merupakan salah satu cara untuk menyelesaikan masalah yang rumit maupun sederhana dengan lebih terstruktur, lebih detail, dan lebih efisien.
// 2. Data struktur Quadratic dan Loglinear
// 3. Faktor - faktor yang mempengaruhi efisiensi suatu program algorithma yaitu:
        //      a) Penggunaan huruf besar dan kecil
        //      b) Penggunaan spasi atau _
        //      c) Penggunaan < atau >
        //      d) Penggunaan . atau ,
        //      e) Penggunaan ;
        //      f) Kesesuaian syntax dengan bahasa pemrograman yang digunakan. Dalam hal ini harus sesuai dengan ketentuan C++
// 4. Yang paling efisien untuk mengurutkan data yang ukurannya kecil yaitu QuickSort. 
//    Karena dengan QuickSort, semakin sedikit data yang ada maka semakin efisien penggunaan QuickSort.
//    QuickSort mengurutkan data mulai dari yang terkecil sampai ke terbesar.  
// 5. Quadratic : BubbleSort, InsertionSort, SelectionSort
//    Loglinear : QuickSort, MergeSort, ShellSort
// 6. Membuat sebuah program pengimplementasian SelectionSort 


#include <iostream>
using namespace std;

int ridwan[54];                         // array of integers to hold valuess
int cmp_count = 0;                      // number of comparasion
int mov_count = 0;                      // number of data movements
int n;

void input() {
    while (true)
    {
        cout << "Masukan panjang element array: ";
        cin >> n;

        if (n <= 54)
            break;
        else
            cout << "\nMaksimum panjang array adalah 54" << endl;
    }

    cout << "\n-------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n-------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> ridwan[i];
    }
}

// swaps the element st index with the element at index y
void swap(int x, int y)
{
    int temp;

    temp = ridwan[x];
    ridwan[x] = ridwan[y];
    ridwan[y] = temp;
}

void q_short(int low, int high)
{
    int pivot, i, rh;
    if (low > high)                                                     // Langkah algoritma No. 1
        return;

    // Partition the list into two parts:
    // One containing element less that or equal to privat
    // Outher containing elements greater than pivot

    pivot = ridwan[low];                                                // Langkah algoritma No. 2
       
    i = low + 1;                                                        // Langkah algoritma No. 3
    rh = high;                                                          // Langkah algoritma No. 4


    while (i <= rh)                                                     // Langkah algoritma No. 10
    {
        // search for an element greather than pivot
        while ((ridwan[i] <= pivot) && (i <= high))                     // Langkah algoritma No. 5
        {
            i++;                                                        // Langkah algoritma No. 6
            cmp_count++;
        }
        cmp_count++;

        // search for an element less than or equal to pivot
        while ((ridwan[rh] > pivot) && (rh >= low))                      // Langkah algoritma No. 7
        {
            rh--;                                                        // Langkah algoritma No. 8
            cmp_count++;
        }
        cmp_count++;
        // if the greater element is on the left of the element
        if (i < rh)                                                          // Langkah algoritma No. 9
        {
            // swap the element at index i with the element at index j
            swap(i, rh);
            mov_count++;
        }
    }

    // j now containt the index of the last element in the sorted list
    if (low < rh)                                                            // Langkah algoritma No. 11
    {
        // move the pivot to its correct position in the list
        swap(low, rh);
        mov_count++;
    }
    // sort the list on the left pivot using quick sort
    q_short(low, rh - 1);                                                    // Langkah algoritma No. 12

    // Sort the list on the right of pivot using quick sort
    q_short(rh + 1, high);                                                   // Langkah algoritma No. 13

}

void display() {
    cout << "\n----------" << endl;
    cout << "Sorted Array" << endl;
    cout << "\n----------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << ridwan[i] << " ";
    }

    cout << "\n\nNumber of comparasion: " << cmp_count << endl;
    cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
    input();
    q_short(0, n - 1);                                                      // Sort the array using quick sort
    display();
    system("pause");

    return 0;
}
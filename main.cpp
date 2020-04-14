#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// InsertionSort - 1

int findSmallestRemainingElement(int array[], int size, int index);
void swap(int array[], int first_index, int second_index);

void sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int index = findSmallestRemainingElement(array, size, i);
        swap(array, i, index);
    }
}

int findSmallestRemainingElement(int array[], int size, int index)
{
    int index_of_smallest_value = index;

    for (int i = index + 1; i < size; i++)
    {
        if (array[i] < array[index_of_smallest_value])
        {
            index_of_smallest_value = i;
        }
    }

    return index_of_smallest_value;
}

void swap(int array[], int first_index, int second_index)
{
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

void showList(int array[], int size)
{
    cout << "\n";

    for (int i = 0; i < size; i++){
        if (i != 0){
            cout << "\n";
        }
        cout << array[i];
    }
    cout << "\n";
}

void insertionSort(int tam) {
    int array[tam], vet[tam];

    for (int i = 0; i < tam; i++){
        array[i] = rand() % 100;
        vet[tam] = i;
    }

    cout << "Original values added to list were: ";
    showList(array, tam);
    cout << '\n';

    sort(array,tam);

    cout << "Ordered list: ";
    showList(array, tam);
    cout << '\n';
}

//SelectionSort - 2

int selectionSort(int tam){

    int array[tam], vet[tam], count, count2;

    for (int i = 0; i < tam; i++){
    array[i] = rand() % 100;
    vet[i] = i;
    }
    int minPosition, temporary;

    cout << "Original values added to list were: ";
    cout << "\n";
    for (int i=0; i<tam; i++){
            cout << array[i] << "\t" << vet[i] << "\n";
    }
    cout << endl;

    for (int i=0; i<tam-1; i++){
            minPosition=i;
            for (int j=i+1; j<tam; j++){
                    count++;
                    if (array[j] < array[minPosition])
                            minPosition = j;
            }
            if (minPosition != i){
                    temporary = array[i];
                    array[i] = array[minPosition];
                    array[minPosition] = temporary;
            }
    }
    for (int i=0; i<tam-1; i++){
            minPosition=i;
            for (int j=i+1; j<tam; j++){
                    count2++;
                    if (vet[j] < vet[minPosition])
                            minPosition = j;
            }
            if (minPosition != i){
                    temporary = vet[i];
                    vet[i] = vet[minPosition];
                    vet[minPosition] = temporary;
            }
    }

    cout << "Ordered list: ";
    cout << "\n";
    for (int i=0; i<tam; i++){
            cout << array[i] << "\t" << vet[i] << "\n";
    }
    cout << "\n" << "random array counter: " << count << "\n";
    cout << "\n" << "ordered array counter: " << count2 << "\n";
}

//BubbleSort - 3

void bubbleSort(int tam) {

    int hold, count, count2;
    int array[tam];
    int vet[tam];

    for (int i=0; i < tam; i++) {
         array[i] = (rand()%100)+1;
        vet[i] = i;
        cout << array[i] << endl;
    }

    cout<<endl;
    cout<<"Original values added to list were: "<<endl;

    for (int j=0; j<tam; j++){
        cout << array[j] << "\t" << vet[j];
        cout << endl;
    }

    cout << endl;

    for (int i=0; i<tam-1; i++){
        for (int j=0; j<tam-1; j++){
                count++;
            if (array[j]>array[j+1]){
                hold=array[j];
                array[j]=array[j+1];
                array[j+1]=hold;
            }
        }
    }

    for (int i=0; i<tam-1; i++){
        for (int j=0; j<tam-1; j++){
                count++;
            if (vet[j]>vet[j+1]){
                hold=vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=hold;
            }
        }
    }

    cout<<"Ordered list: "<<endl;

    for (int i=0; i<tam; i++){
        cout << array[i]<< "\t" << vet[i] << endl;
    }
    cout << "\n" << "random array counter: " << count << "\n";
    cout << "\n" << "ordered array counter: " << count2 << "\n";
}

//QuickSort - 4

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition2(int data[],int l,int h){
    int i=l-1,j;
    int pivot = data[h];
    for (j=l;j<h;j++){
        if (data[j]<=pivot){
            i++;
            swap(&data[i],&data[j]);
        }
    }
    swap(&data[h],&data[i+1]);
    return i+1;
}

int partition1(int data[],int l,int h){
    int pivot = data[l];
    while(l<h){
        while(l<h && data[h]>=pivot)h--;
        data[l]=data[h];
        while(l<h && data[l]<=pivot)l++;
        data[h]=data[l];
    }
    data[l]=pivot;
    return l;
}
int partition1_1(int data[],int l,int h){
    int pivot = data[l];
    while(l<h){
        while(l<h && data[h]>=pivot)h--;
        swap(&data[l],&data[h]);
        while(l<h && data[l]<=pivot)l++;
        swap(&data[l],&data[h]);
    }
    return l;
}
void quickSort2(int data[],int l,int h){
    if (l<h){
        int pivot = partition2(data,l,h);
        quickSort2(data,l,pivot-1);
        quickSort2(data,pivot+1,h);
    }
}

int quickSort(int tam) {
      int array[tam];

    cout<<"Original values added to list were: "<<endl;

      for (int i = 0; i < tam; i++){
    array[i] = rand() % 100;
        cout << array[i];
        cout << "\n";
    }

    cout << "\n";
    cout<<"Ordered list: "<<endl;

    quickSort2(array,0,tam-1);
    for (int t=0;t<tam;t++){
        cout<<array[t]<<" "<<endl;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int tamanhoArray, metodoOrdenacao;

    cout << "Type a value to define the list's size: ";
    cin >> tamanhoArray;
    cout << "Choose the sorting type, insertionSort = 1, selectionSort = 2, bubbleSort = 3 ou quickSort = 4: ";
    cin >> metodoOrdenacao;

    if (metodoOrdenacao == 3){
        bubbleSort(tamanhoArray);
    } else if (metodoOrdenacao == 1){
        insertionSort(tamanhoArray);
    } else if (metodoOrdenacao == 2){
        selectionSort(tamanhoArray);
    } else if (metodoOrdenacao == 4){
        quickSort(tamanhoArray);
    }
}

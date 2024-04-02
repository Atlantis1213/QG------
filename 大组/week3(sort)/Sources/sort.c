#include<stdio.h>
#include<sort.h>
#include<stdlib.h>
/*****************************插入排序*********************************/

void insertSort(int* a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i;

        while (j > 0 && a[j - 1] > temp)
        {
            a[j] = a[j - 1];
            j--;
        }

        a[j] = temp;
    }
}


/*****************************归并排序*********************************/


void MergeArray(int* a, int begin,  int mid, int end, int* temp)
{
    for (int i = begin; i <= end; i++)
    {
        temp[i] = a[i];
    }
    int i = begin, j = mid + 1;
    for (int k = begin; k <=end; k++)
    {
        if (i == mid + 1) {
            a[k] = temp[j];
            j++;
        }
        else if (temp[i] <= temp[j]) {
            a[k] = temp[i];
            i++;
        }
        else if (j == end+1) {
            a[k] = temp[i];
            i++;
        }
        else {
            a[k] = temp[j];
            j++;
        }
    }



    return;
}

void MergeSort(int* a, int begin, int end, int* temp)
{
    if (begin == end) return;
    int mid = (begin + end) >> 1;//相当于除2，但是比除法运算符要快一点
    MergeSort(a, begin, mid,temp);
    MergeSort(a, mid + 1, end, temp);
    MergeArray(a, begin, mid, end, temp);
    return;
}

void MergeSortArray(int* a, int size) {
    int begin = 0,end;
    int *temp=(int*)malloc(size*sizeof(int));
    end = size - 1;
    MergeSort(a, begin, end, temp);
}

/*****************************快速排序（递归法）*********************************/

void QuickSort_Recursion(int* a, int begin, int end)
{
    if (begin >= end)
        return;
    int pivot = a[begin];
    int temp;
    int end0 = end, begin0 = begin;
    while (begin < end)
    {
        while (a[end] >= pivot&&begin<end) {
            end--;
        }
        if (a[end] < pivot)
        {
            a[begin] = a[end];
        }
        while (a[begin] <= pivot&&begin<end)
        {
            begin++;
        }
        if (a[begin] > pivot)
        {
            a[end] = a[begin];
        }
    }
    a[begin] = pivot;
    QuickSort_Recursion(a, begin0, end - 1);
    QuickSort_Recursion(a, end + 1, end0);
}

/*****************************快速排序（非递归法）*********************************/
void QuickSort(int* a, int size) 
{
    int* stack = (int*)malloc(size * sizeof(int));
    int top = -1;

    stack[++top] = 0;
    stack[++top] = size - 1;

    while (top >= 0) {
        int end = stack[top--];
        int begin = stack[top--];
        int pivot = a[begin];
        int end0 = end, begin0 = begin;

        while (begin < end) {
            while (a[end] >= pivot && begin < end) {
                end--;
            }
            if (a[end] < pivot) {
                swap(&a[begin], &a[end]);
            }
            while (a[begin] <= pivot && begin < end) {
                begin++;
            }
            if (a[begin] > pivot) {
                swap(&a[end], &a[begin]);
            }
        }

        if (begin < end0) {
            stack[++top] = begin + 1;
            stack[++top] = end0;
        }
        if (begin0 < begin - 1) {
            stack[++top] = begin0;
            stack[++top] = begin - 1;
        }
    }
}
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*****************************计数排序*********************************/
void CountSort(int* a, int size, int max)
{
    int k;
    int* cnt = (int*)malloc((max+1) * sizeof(int)); 
    for ( k = 0; k <= max; k++) {
        cnt[k] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        cnt[a[i]]++;
    }
    k = 0;
    for (int i = 0; i <= max; i++)
    {
        if (cnt[i] != 0)
        {
            for (int j=0; j < cnt[i]; j++)
            {
                a[k] = i;
                k++;
            }
        }
    }
}

/*****************************基数排序*********************************/

void RadixCountSort(int* a, int size)
{
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = { 0 };  
        int *output=(int*)malloc(size*sizeof(int));
        for (int i = 0; i < size; i++) {
            count[(a[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = size - 1; i >= 0; i--) {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }
        for (int i = 0; i < size; i++) {
            a[i] = output[i];
        }
    }
}

/*****************************颜色排序*********************************/
void ColorSort(int* a, int size)
{
    int p1 = 1, p0 = 0, p2 = size - 1,temp;
    for (p1 = 0; p1 <= p2;) 
    {      
        if (a[p1] == 0)
        {
            temp = a[p1];
            a[p1] = a[p0];
            a[p0] = temp;
            p0++;
            p1++;
        }
        else if (a[p1] == 2)
        {
            temp = a[p1];
            a[p1] = a[p2];
            a[p2] = temp;
            p2--;
        }
        else p1++;
                    

    }
}

/*****************************找第k小的数*********************************/

int findksmall(int* a, int size, int k)
{
    int cnt = 0,i;
    k--;
    QuickSort_Recursion(a, 0, size - 1);
    for ( i = 1; cnt < k && i < size; i++)
    {
        if (a[i] != a[i - 1]) cnt++;
    }


    return a[i-1];
}

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<sort.h>
#include<time.h>
#include <windows.h>
#include<stdlib.h>

void generateRandomNumbers(int count, int min, int max);
void readRandomNumbers(int* numbers, int count);

int main()
{
	int size = 10000;
	int* test= (int*)malloc(size * sizeof(int));
	int a[10] = {0,2,2,4,5,6,7,8,9,0};
	int k;
	LARGE_INTEGER frequency, start, end;
	double elapsed_time;

	printf("10000数据量用时：\n");

	generateRandomNumbers(size, 0, 100000);
	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start); 
	MergeSortArray(test, size);
	QueryPerformanceCounter(&end); 
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; 
	printf("归并排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	insertSort(test, size);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("插入排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	QuickSort_Recursion(test, 0, size - 1);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("递归排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	CountSort(test, size, 100000);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("计数排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	RadixCountSort(test, size);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("基数排序用时：%lfs\n", elapsed_time);

	printf("-------------------\n");
	size = 50000;
	free(test);
	test = (int*)malloc(size * sizeof(int));
	printf("50000数据量用时：\n");

	generateRandomNumbers(size, 0, 100000);
	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	MergeSortArray(test, size);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("归并排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	insertSort(test, size);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("插入排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	QuickSort_Recursion(test, 0, size - 1);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("递归排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	CountSort(test, size, 100000);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("计数排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	RadixCountSort(test, size);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("基数排序用时：%lfs\n", elapsed_time);

	printf("-------------------\n");

	size = 200000;
	free(test);
	test = (int*)malloc(size * sizeof(int));
	printf("200000数据量用时：\n");

	generateRandomNumbers(size, 0, 100000);
	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	MergeSortArray(test, size);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("归并排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	insertSort(test, size);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("插入排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	QuickSort_Recursion(test, 0, size - 1);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("递归排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	CountSort(test, size, 100000);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("计数排序用时：%lfs\n", elapsed_time);

	readRandomNumbers(test, size);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	RadixCountSort(test, size);
	QueryPerformanceCounter(&end);
	elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	printf("基数排序用时：%lfs\n", elapsed_time);

	printf("----------------------\n100数据量下排序100k次用时：\n");

	elapsed_time = 0;
	test = (int*)malloc(100 * sizeof(int));
	generateRandomNumbers(100, 0, 1000);
	for (int i = 0; i < 100000; i++)
	{		
		readRandomNumbers(test, 100);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start);
		MergeSortArray(test, 100);
		QueryPerformanceCounter(&end);
		elapsed_time += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}
	printf("归并排序用时：%lfs\n", elapsed_time);

	elapsed_time = 0;
	for (int i = 0; i < 100000; i++)
	{
		readRandomNumbers(test, 100);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start);
		insertSort(test, 100);
		QueryPerformanceCounter(&end);
		elapsed_time += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}
	printf("插入排序用时：%lfs\n", elapsed_time);

	elapsed_time = 0;
	for (int i = 0; i < 100000; i++)
	{
		readRandomNumbers(test, 100);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start);
		QuickSort_Recursion(test, 0, 99);
		QueryPerformanceCounter(&end);
		elapsed_time += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}
	printf("快速排序用时：%lfs\n", elapsed_time);

	elapsed_time = 0;
	for (int i = 0; i < 100000; i++)
	{
		readRandomNumbers(test, 100);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start);
		CountSort(test, 100, 1000);
		QueryPerformanceCounter(&end);
		elapsed_time += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}
	printf("计数排序用时：%lfs\n", elapsed_time);

	elapsed_time = 0;
	for (int i = 0; i < 100000; i++)
	{
		readRandomNumbers(test, 100);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start);
		RadixCountSort(test, 100);
		QueryPerformanceCounter(&end);
		elapsed_time += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}
	printf("基数排序用时：%lfs\n", elapsed_time);
	return 0;
}

void generateRandomNumbers(int count, int min, int max) {
	FILE* file = fopen("random_numbers.txt", "w");
	if (file == NULL) {
		printf("无法打开文件！");
		return;
	}
	srand(time(0));
	for (int i = 0; i < count; i++) {
		int num = (rand() % (max - min + 1)) + min;
		fprintf(file, "%d\n", num);
	}
	fclose(file);
}

void readRandomNumbers(int* numbers, int count) {
	FILE* file = fopen("random_numbers.txt", "r");
	if (file == NULL) {
		printf("无法打开文件！");
		return;
	}

	for (int i = 0; i < count; i++) {
		char line[20];
		fgets(line, sizeof(line), file);
		sscanf(line, "%d",&numbers[i]);
	}

	fclose(file);
}
/*****************插入排序***********************/

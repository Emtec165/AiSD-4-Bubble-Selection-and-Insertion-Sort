#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
using namespace std;

void bubbleSort(int input[], unsigned int &count, int &n) {
	bool przestawienie = true;
	int j = 0, tmp;
	while (przestawienie) {
		przestawienie = false;
		j++;
		for (int i = 0; i < n - j; i++) {
			if (input[i] > input[i + 1]) {
				tmp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = tmp;
				przestawienie = true;
				count++;
			}
		}
	}
}

void selectionSort(int input[], unsigned int &count, int &n) {
	int i, j, minIndex, tmp;
	for (i = 0; i < n - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < n; j++)
		if (input[j] < input[minIndex])
			minIndex = j;
		if (minIndex != i) {
			tmp = input[i];
			input[i] = input[minIndex];
			input[minIndex] = tmp;
			count++;
		}
	}
}

void insertionSort(int input[], unsigned int &count, int &n) {
	int temp, j;
	for (int i = 1; i < n; ++i) {
		temp = input[i];
		j = i;
		while (j > 0 && input[j - 1] > temp) {
			count++;
			input[j] = input[j - 1];
			j--;
		}
		if (input[j] != temp) {
			count++;
			input[j] = temp;
		}
	}
	//int i, j, tmp; DZI£A WOLNIEJ ALE JEST FAJNIEJSZE
	//for (i = 1; i < n; i++) {
	//	j = i;
	//	tmp = input[j];
	//	while (j > 0 && input[j - 1] > tmp) {
	//		input[j] = input[j - 1];
	//		input[j - 1] = tmp;
	//		j--;
	//		count++;
	//	}
	//}
}

int main(void) {
	int input_array[10], input_array2[10], input_array3[10], n = 10;
	unsigned int count = 0;
	for (int i = 0; i < n; i++)
		input_array[i] = input_array2[i] = input_array3[i] = rand() % 10000;

	ofstream myfile("input.txt");
	if (myfile.is_open()) {
		for (int i = 0; i < n; i++)
			myfile << input_array[i] << endl;
		myfile.close();
	}
	else cout << "Unable to open file";

	////////////////////////////////////////////////////////BUBBLE SORT////////////////////////////////////////////////////////////
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	bubbleSort(input_array, count, n);

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	cout << "W Bubble Sorcie nastapilo " << count << " przestawien.\n";
	cout << "Czas wykonania Bubble Sort wynosi " << elapsed_seconds.count() << "s\n\n";

	ofstream BubbleSortOUT("Bubble_Sort_Output.txt");
	if (BubbleSortOUT.is_open()) {
		for (int i = 0; i < n; i++)
			BubbleSortOUT << input_array[i] << endl;
		BubbleSortOUT.close();
	}
	else cout << "Unable to open file";

	/////////////////////////////////////////////////////SELECTION SORT////////////////////////////////////////////////////////////
	count = 0;
	start = std::chrono::system_clock::now();

	selectionSort(input_array2, count, n);

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end - start;

	cout << "W Selection Sorcie nastapilo " << count << " przestawien.\n";
	cout << "Czas wykonania Selection Sort wynosi " << elapsed_seconds2.count() << "s\n\n";

	ofstream SelectionSortOUT("Selection_Sort_Output.txt");
	if (SelectionSortOUT.is_open()) {
		for (int i = 0; i < n; i++)
			SelectionSortOUT << input_array2[i] << endl;
		SelectionSortOUT.close();
	}
	else cout << "Unable to open file";

	/////////////////////////////////////////////////////INSERTION SORT////////////////////////////////////////////////////////////
	count = 0;
	start = std::chrono::system_clock::now();

	insertionSort(input_array3, count, n);
	
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds3 = end - start;

	cout << "W Insertion Sorcie nastapilo " << count << " przestawien i przesuniec.\n";
	cout << "Czas wykonania Selection Sort wynosi " << elapsed_seconds3.count() << "s\n\n";

	ofstream InsertionSortOUT("Insertion_Sort_Output.txt");
	if (InsertionSortOUT.is_open()) {
		for (int i = 0; i < n; i++)
			InsertionSortOUT << input_array3[i] << endl;
		InsertionSortOUT.close();
	}
	else cout << "Unable to open file";

	system("pause");
	return 0;
}
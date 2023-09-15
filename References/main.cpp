#include <iostream>
//#include <math> /// для математических функций например pow()!!!

void my_swap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

void p_swap(int* pn1, int* pn2) {
	int tmp = *pn1;
	*pn1 = *pn2;
	*pn2 = *pn1;
}

void r_swap(int& var1, int& var2) {
	int tmp = var1;
	var1 = var2;
	var2 = tmp;
}

int& rmax(int arr[],const int length) {
	int max_index = 0;
	for (int i = 1; i < length; i++)
		if (arr[max_index] < arr[i])
			max_index = i;

	return arr[max_index];
}

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

template <typename T>
void ref_dbl(T& var1, T& var2);

int* greater_arr(int arr1[],const int length1, int arr2[], const int length2,bool& first);

int& mean_arr(int arr[], const int length);

int main() {
	setlocale(LC_ALL, "Russian");
	int n,m;

	
	// Ссылки на переменндые

	/*n = 7;

	int& refn = n;

	std::cout << "n = " << n << std::endl;
	std::cout << "refn = " << refn << std::endl;
	
	refn = 8;
	std::cout << "n = " << n << std::endl;

	n = 43;
	std::cout << "refn = " << refn << std::endl;

	std::cout << "&refn = " << &refn << std::endl;
	std::cout << "&n    = " << &n << std::endl;*/


	// Ссылки как параметры функции

	//n = 7;
	//m = 15;
	//std::cout << "n = " << n << ", ";
	//std::cout << "m = " << m << std::endl;
	//// my_swap(n,m); // не работает
	//// p_swap(&n,&m); // работает но неудобно
	//r_swap(n, m); // работает удобно
	////std::swap(n,m);
	//std::cout << "n = " << n << ", ";
	//std::cout << "m = " << m << std::endl;


	// Ссылки как результаты работы функций

	//const int size = 5;
	//int arr[size] = { 6,7,2,7,5 };
	//std::cout << "Исходный массив:\n";
	//print_arr(arr, size);
	//std::cout << "Максимум: " << rmax(arr, size) << "\n\n";
	//rmax(arr, size) = -1;
	//print_arr(arr, size);

	// Задча 1. Квадрат или обнуление

	/*std::cout << "Задача 1.\nВведите два числа ->";
	std::cin >> n >> m;
	ref_dbl(n, m);

	std::cout << "n = " << n << ", m = " << m << "\n\n";*/

	// Задача 2. указатель на массив

	/*std::cout << "Задача 2.\nМассив А: ";
	const int sizeA = 7, sizeB = 6;
	int A[sizeA]{ 3,4,5,6,1, 10,3 };
	int B[sizeB]{ 10, 20, 30, 40, 50, 60 };

	print_arr(A, sizeA);
	std::cout << "Массив B: ";
	print_arr(B, sizeB);

	bool f;
	int* pointer = greater_arr(A, sizeA, B, sizeB, f);
	std::cout << "Длиннейший: ";
	print_arr(pointer, f ? sizeA : sizeB);*/

	// Задача 3. число самое близкое к среднему арифметическому

	/*const int size3 = 10;
	int arr3[size3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::cout << "Задача 3.\nИсходный массив: ";
	print_arr(arr3, size3);
	std::cout << "Число массива близкое к среднему: " <<
		mean_arr(arr3, size3) << "\n\n";*/

	// Задача 4. копирование массива через указатель

	/*const int size4 = 5;
	int arr4[size4] = { 1,2,3,4,5 };
	int arr5[size4] = {};

	int* parr4;
	int* parr5;

	parr4 = arr4;
	parr5 = arr5;

	std::cout << "Задача 4.\nМассив 1: ";
	print_arr(parr4, size4);
	
	for (int i = 0; i < size4; i++)
		*(parr5 + size4 - 1 - i) = *(parr4 + i);

	std::cout << "Массив 2: ";
	print_arr(parr5, size4);*/

	// Задача 5. массив равный сумме упорядоченных массивов

	const int size6 = 10;
	const int size7 = 8;

	int arr6[size6] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr7[size7] = { 3, 22, 23, 24, 25, 26, 27, 28 };

	int arr8[size6 + size7]{};

	int min;
	int max;

	if (arr6[0] <= arr7[0])
		min = arr6[0];
	else
		min = arr7[0];

	if (arr6[size6 - 1] >= arr7[size7 - 1])
		max = arr6[size6 - 1];
	else
		max = arr7[size7 - 1];

	std::cout << "Min = " << min << std::endl;
	std::cout << "Max = " << max << std::endl;


	int a = 0, b = 0, c = 0; // индексы массивов

	for (int i = min; i <= max; i++) {
		
		if (arr6[a] == i && arr7[b] == i) {
			arr8[c] = i;
			c++;
			arr8[c] = i;
			a++;
			b++;
			c++;
		}
		else
			if (arr6[a] == i) {
				arr8[c] = i;
				a++;
				c++;
			}			
			else
				if (arr7[b] == i) {
					arr8[c] = i;
					b++;
					c++;
				}
}

	std::cout << "Задача 5\nМассив 1: ";
	print_arr(arr6, size6);
	std::cout << "Массив 2: ";
	print_arr(arr7, size7);
	std::cout << "Массив 3: ";
	print_arr(arr8, size6 + size7);
	
	return 0;
}


int* greater_arr(int arr1[], const int length1, int arr2[], const int length2,bool& first) {

	return (first = length1 > length2) ? arr1 : arr2;

}

int& mean_arr(int arr[], const int length)
{
	// TODO: insert return statement here
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	double mean = sum / (double)length;
	double min = mean - (double)arr[0];
	int min_index = 0;
	for (int i = 1; i < length; i++) {
		if (min > std::abs(mean - (double)arr[i])) {
			min = std::abs(mean - (double)arr[i]);
			min_index = i;
		}
	}

	return arr[min_index];			
}



template <typename T>
void ref_dbl(T& var1, T& var2) {
	if (var1 > var2) {
		var1 *= var1; // var1 = pow(var1,2);
		var2 *= var2; // var2 = pow(var2,2);
		return;
	}
		var1 = 0;
		var2 = 0;
}
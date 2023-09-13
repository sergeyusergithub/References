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

	std::cout << "Задача 2.\nМассив А: ";
	const int sizeA = 7, sizeB = 6;
	int A[sizeA]{ 3,4,5,6,1, 10,3 };
	int B[sizeB]{ 10, 20, 30, 40, 50, 60 };

	print_arr(A, sizeA);
	std::cout << "Массив B: ";
	print_arr(B, sizeB);

	bool f;
	int* pointer = greater_arr(A, sizeA, B, sizeB, f);
	std::cout << "Длиннейший: ";
	print_arr(pointer, f ? sizeA : sizeB);

	
	return 0;
}


int* greater_arr(int arr1[], const int length1, int arr2[], const int length2,bool& first) {

	return (first = length1 > length2) ? arr1 : arr2;

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
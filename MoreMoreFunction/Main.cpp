#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (right - left + 1) + left;
	}

}

template <typename T>
void print_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << std::endl;
}

template<typename T>
int search_index(T arr[],const int length, T key,int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == key)
			return i;
	return -1;
}

template<typename T>
int search_last_index(T arr[], const int length, T key) {
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == key)
			return i;
	return -1;
}

template <typename T>
int search_last_index(T arr[], const int length, T key, int begin) {
	for (int i = begin; i >= 0; i--)
		if (arr[i] == key)
			return i;
	return -1;
}

int arr_min(int arr[], const int length) {
	int min = arr[0];
	for (int i = 1; i < length; i++) {
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

int arr_max(int arr[], const int length) {
	int max = arr[0];
	for (int i = 1; i < length; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

double mean_value(int arr[], const int length) {
	double value = arr[0];
	for (int i = 1; i < length; i++)
		value += arr[i];
	return value / length;
}

void range(int arr[], const int length, int a, int b) {
	if (a > b)
		std::swap(a, b);
	for (int i = 0; i < length; i++)
		if (arr[i] >= a && arr[i] <= b)
			std::cout << arr[i] << ' ';
	std::cout << ' ';
}

int count(int arr[], const int length, int x) {
	int count = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == x)
			count++;
	return count;
}
void sort_arr(int arr[], const int length) {
	for (int i = length - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}



int main() {
	setlocale(LC_ALL, "ru");
	int n;

	const int size = 20;
	int arr[size]{};
	std::cout << "Изначальный массив:\n";
	fill_arr(arr, size, -50, 50);
	print_arr(arr, size);
	std::cout << "\n\n";
	//Индекс первого вхождения
	std::cout << "Введите значение элемента из массива ->";
	std::cin >> n;
	std::cout << "Номер первого вхождения элемента в массив " << search_index(arr, size, n);
	std::cout << "\n\n";
	//Индекс последнего вхождения
	std::cout << "Введите значение элемента из массива ->";
	std::cin >> n;
	std::cout << "Номер последнего вхождения элемента в массив " << search_last_index(arr, size, n);
	std::cout << "\n\n";
	//Минимальное значение
	std::cout <<"Минимальное значение в массиве = " << arr_min(arr, size);
	std::cout << "\n\n";
	//Максимальное значение
	std::cout << "Максимальное значение в массиве = " << arr_max(arr, size);
	std::cout << "\n\n";
	//Среднеарифметическое значение массива
	std::cout << "Среднеарифметическое значение всех элементов массива = " << mean_value(arr, size);
	std::cout << "\n\n";
	//Поиск в заданном диапазоне
	std::cout << "Элементы входящие в заданный диапазон -> ";
	range(arr, size, 4, 10);
	std::cout << "\n\n";
	//Колличество вхождений элемента
	std::cout << "Введите элемент ->";
	std::cin >> n;
	std::cout << "Колличкство вхождений заданного элемента = " << count(arr, size,n);
	std::cout << "\n\n";
	//Пузырьковая сортировка
	sort_arr(arr, size);
	std::cout << "Отсортированный массив ->\n";
	print_arr(arr, size);




	return 0;
}
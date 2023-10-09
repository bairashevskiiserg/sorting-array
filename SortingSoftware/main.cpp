#include <iostream>
#include <ctime>
#include <fstream>
#include <limits>
#include "sorting.h"


int main() {
	setlocale(LC_ALL, "ru");

	int size_array;
	std::cout << "Введите необходимое количество значений для вашего массива: ";
	while (true)
	{
		if (std::cin >> size_array && size_array <= 1000000 && size_array > 0) {
			break;
		}
		else {
			std::cout << "\n" << "Введено непраивильное значение. Пожалуйста, введите число от 1 до 1 000 000: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	CreateArray object_for_generation = CreateArray(size_array);


	std::ofstream fout;
	std::string path_unsorted_numbers = "input.txt";
	int seed;
	std::cout << "\n" << "Введите стартовое значение сида: ";
	while (true)
	{
		if (std::cin >> seed && seed <= 1000000 && seed > 0) {
			break;
		}
		else {
			std::cout << "\n" << "Введено непраивильное значение. Пожалуйста, введите натуральное число, не большее, чем 1 000 000: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	std::cout << "\n" << "Начинаем наполнение массива.";
	object_for_generation.fill_array(seed);
	fout.open(path_unsorted_numbers);
	for (int i = 0; i < size_array; i++)
	{
		fout << object_for_generation.main_array[i] << ' ';
	}
	fout.close();
	std::cout << "\n" << "Наполнение массива окончено.";


	std::cout << "\n\n" << "Выберите способ сортировки чисел:\n1 - По возрастанию\n2 - По убыванию" << "\n\n";
	while (true)
	{
		if (std::cin >> object_for_generation.user_choice && (object_for_generation.user_choice == 1 || object_for_generation.user_choice == 2)) {
			break;
		}
		else {
			std::cout << "\n" << "Введено непраивильное значение. Пожалуйста, введите 1, если необходима возрастающая последловательность"\
						"чисел или 2, если убывающая последловательность чисел: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	std::string path_sorted_numbers = "output.txt";
	std::cout << "\n" << "Начинаем сортировку массива.";
	object_for_generation.quick_sort(0, size_array-1);
	fout.open(path_sorted_numbers);
	for (int i = 0; i < size_array; i++)
	{
		fout << object_for_generation.main_array[i] << ' ';
	}
	fout.close();
	object_for_generation.delete_array();
	std::cout << "\n" << "Сортировка массива окончена.";

	std::cout <<"\n\n" << object_for_generation.check_arrays();

	object_for_generation.~CreateArray();
	system("notepad.exe input.txt");
	system("notepad.exe output.txt");
	return 0;
}
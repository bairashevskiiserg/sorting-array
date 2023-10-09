#include <iostream>
#include "sorting.h"

CreateArray::CreateArray(int size_array) {
	max_number_array = size_array;
	main_array = new unsigned int[size_array];
	unsorted_array = new unsigned int[size_array];
	time_to_complete = 0;
	user_choice = 0;
}

void CreateArray::fill_array(int value) {
	unsigned int seed = value;

	const int multiplier = 1103515245;
	const int addend = 12345;
	const int mask = 0x7fffffff;

	for (int i = 0; i < max_number_array; i++)
	{
		seed = (seed * multiplier + addend) % mask;
		main_array[i] = seed % max_number_array;
		unsorted_array[i] = seed % max_number_array;
	}
}

void CreateArray::swap_places(unsigned int& left_element, unsigned int& right_element) {
	int temporary = left_element;
	left_element = right_element;
	right_element = temporary;
}

int CreateArray::splitting_for_increasing_sequence(int min_index, int max_index) {
	int pivot = min_index;

	for (int i = min_index; i <= max_index; i++)
	{
		if (main_array[i] < main_array[max_index])
		{
			swap_places(main_array[pivot], main_array[i]);
			pivot++;
		}
	}

	time_to_complete++;
	if (time_to_complete % 100000 == 0) {

		std::cout << "\n" << time_to_complete << " элемент отсортирован." << "\n";
	}

	swap_places(main_array[pivot], main_array[max_index]);

	return pivot;
}

int CreateArray::splitting_for_decreasing_sequence(int min_index, int max_index) {
	int pivot = min_index;

	for (int i = min_index; i <= max_index; i++)
	{
		if (main_array[i] > main_array[max_index])
		{
			swap_places(main_array[pivot], main_array[i]);
			pivot++;
		}
	}

	time_to_complete++;
	if (time_to_complete % 100000 == 0) {
		std::cout << "\n" << time_to_complete << " элемент отсортирован." << "\n";
	}
	
	swap_places(main_array[pivot], main_array[max_index]);
	return pivot;
}

void CreateArray::quick_sort(int min_index, int max_index) {
	if (min_index >= max_index)
	{
		return;
	}

	if (user_choice == 1)
	{
		int pivot_index = splitting_for_increasing_sequence(min_index, max_index);
		quick_sort(min_index, pivot_index - 1);
		quick_sort(pivot_index + 1, max_index);
	}
	else {
		int pivot_index = splitting_for_decreasing_sequence(min_index, max_index);
		quick_sort(min_index, pivot_index - 1);
		quick_sort(pivot_index + 1, max_index);
	}
}

std::string CreateArray::check_arrays() {
	int index_check_elem = 0;
	for (int i = 0; i < max_number_array; i++)
	{
		if (main_array[index_check_elem] == unsorted_array[i])
		{
			unsorted_array[i] = 0;
			if (index_check_elem == max_number_array - 1)
			{
				return "ќтсортированный массив соответствует исходному массиву.";
			}
			else
			{
				i = 0;
				index_check_elem++;
			}
		}
	}
	return "ƒанные исходного массива были повреждены или утер€ны.";
}
	

void CreateArray::delete_array() {
	delete[] main_array;
	delete[] unsorted_array;
}



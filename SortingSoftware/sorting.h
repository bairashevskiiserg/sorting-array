#pragma once
#include <iostream>

class CreateArray {
private:
	int max_number_array;
	int time_to_complete;
public:
	unsigned int* main_array;
	unsigned int* unsorted_array;
	int user_choice;
	CreateArray(int size_array);

	void fill_array(int value);

	void swap_places(unsigned int& left_element, unsigned int& right_element);
	int splitting_for_increasing_sequence(int min_index, int max_index);
	int splitting_for_decreasing_sequence(int min_index, int max_index);
	void quick_sort(int min_index, int max_index);

	std::string check_arrays();

	void delete_array();
};


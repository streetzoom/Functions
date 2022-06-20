#include <iostream>
#include <vector>
#include <algorithm>
/*
    Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses functions.

    You decide how to modularize the program.
*/

// func prototypes that handle menu display & user input
void display_menu();
char user_input();

// func prototypes that handle main functionality
void print_number(const std::vector<int>&);
void add_number(std::vector<int>&);
void mean_of_numbers(const std::vector<int>&);
void smallest_number(const std::vector<int>&);
void largest_number(const std::vector<int>&);
void find_number(const std::vector<int>&);
void quit();

// func prototypes that work with list(in this case - vector)
void display_list(const std::vector<int>&);
double calc_mean(const std::vector<int>&);
int calc_smallest(const std::vector<int>&);
int calc_largest(const std::vector<int>&);
bool find(const std::vector<int>&, int);

int main () {
    std::vector<int> user_data {};
    char user_choice {};
    do {
        display_menu();
        user_choice = user_input();
        switch (user_choice) {
            case 'P':
                print_number(user_data);
                break;
            case 'A':
                add_number(user_data);
                break;
            case 'M':
                mean_of_numbers(user_data);
                break;
            case 'S':
                smallest_number(user_data);
                break;
            case 'L':
                largest_number(user_data);
                break;
            case 'F':
                find_number(user_data);
                break;
            case 'Q':
                quit();
                break;
            default:
                std::cout << "Unknown selection, please try again" << std::endl;
        }
    } while (user_choice != 'Q');
    return 0;
}

// func that display main menu
void display_menu() {
    std::cout << std::endl;
    std::cout << "\nP - Print numbers" << std::endl;
    std::cout << "A - Add a number" << std::endl;
    std::cout << "M - Display mean of the numbers" << std::endl;
    std::cout << "S - Display the smallest number" << std::endl;
    std::cout << "L - Display the largest number" << std::endl;
    std::cout << "F - Find a number" << std::endl;
    std::cout << "Q - Quit" << std::endl;
    std::cout << "\nEnter your choice:";
}

// func that handle user choice & return it as upper case
inline char user_input() {
    char choice {};
    std::cin >> choice;
    return static_cast<char>(std::toupper(static_cast<unsigned char>(choice)));
}

/***************************************************************
func is called when the user selects the display list option from the main menu.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
void print_number (const std::vector<int> &user_data) {
    if (user_data.empty()) {
        std::cout << "[] - the list is empty";
    } else {
        display_list(user_data);
    }
}

/***************************************************************
func is called when the user selects add a number to the list from the main menu.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
void add_number (std::vector<int> &user_data) {
    int number_to_add {};
    std::cout << "Enter an integer to add to the list: " << std::endl;
    std::cin >> number_to_add;
    user_data.push_back(number_to_add);
    std::cout << number_to_add << " added";
}

/***************************************************************
func is called when the user selects calculate the mean from the main menu.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
void mean_of_numbers(const std::vector<int> &user_data) {
    if (user_data.empty()) {
        std::cout << "Unable to calculate the mean - no data";
    } else {
        std::cout << "The mean is: " << calc_mean(user_data);
    }
}

/***************************************************************
func is called when the user selects the smallest option from the main menu.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
void smallest_number(const std::vector<int> &user_data) {
    if (user_data.empty()) {
        std::cout << "Unable to determine the smallest number - list is empty";
    } else {
        std::cout << "The smallest number is: " << calc_smallest(user_data);
    }
}

/***************************************************************
func is called when the user selects the largest option from the main menu.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
void largest_number(const std::vector<int> &user_data) {
    if (user_data.empty()) {
        std::cout << "Unable to determine the largest number - list is empty";
    } else {
        std::cout << "The largest element is: " << calc_largest(user_data);
    }
}

/***************************************************************
func is called when the user selects the find option from the main menu.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
void find_number(const std::vector<int> &user_data) {
    int target {};
    std::cout << "Enter the number to find:";
    std::cin >> target;
    if (find(user_data, target)) {
        std::cout << target << " was found" << std::endl;
    } else {
        std::cout << target << " was not found" << std::endl;
    }
}

// func handle user quit choice
void quit() {
    std::cout << "Goodbye" << std::endl;
}

/***************************************************************
func expects a list of integers as a vector and displays all the integers in the list in square brackets.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
void display_list(const std::vector<int> &user_data) {
    std::cout << "[ ";
    for (auto vec: user_data) {
        std::cout << vec << " ";
    }
    std::cout << " ]";
}

/***************************************************************
func expects a list of integers as a vector and returns the calculated mean.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
double calc_mean(const std::vector<int> &user_data) {
    double average_data {};
    double total_data{};
    for (auto vec: user_data) {
        total_data += vec;
        average_data = total_data / user_data.size();
    }
    return average_data;
}

/***************************************************************
func expects a list of integers as a vector and returns the smallest integer in the list.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
inline int calc_smallest(const std::vector<int> &user_data) {
    return *std::min_element(user_data.begin(), user_data.end());
}

/***************************************************************
func expects a list of integers as a vector and returns the largest integer in the list.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
inline int calc_largest(const std::vector<int> &user_data) {
    return *std::max_element(user_data.begin(), user_data.end());
}

/***************************************************************
func searches the list of integers as a vector for the given integer target.
func should NOT modify the list of numbers so the parameter is a const reference.
***************************************************************/
bool find(const std::vector<int> &user_data, int target) {
    for (auto vec: user_data) {
        if (vec == target) {
            return true;
        }
    }
    return false;
}
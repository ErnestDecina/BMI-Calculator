/*
Program Desc: 
{
	Create an application that will get input from a user: First_Name, Last_Name, Age, Height, Weight
	Then program will calculate the users BMI then store it on a .txt file called: "BMI_Calculations"
}
Author: Ernest-John Decina
Date: 5th May 2022
*/

// Header Files
#include <iostream>
#include <fstream>

// Symobolic Names
#define NAME_SIZE 256

// Classes
class person_details
{
	public:
		char firstname[NAME_SIZE];
		char lastname[NAME_SIZE];
		int age;
		float height;
		float weight;
		float BMI;
};

// Function Prototypes
void menu(void);
void option_menu(bool *);
void read_user_data(class person_details*);
void calculate_BMI(class person_details*);
void save_data(class person_details*);
void clearbuffer(void);

// Driver Code
int main()
{
	// Vars
	bool menu_status = true;

	do
	{
		// Prints menu
		menu();
		option_menu(&menu_status);
	} while(menu_status == true); // End do while

	// Ending main function
	return 0;
} // End main

// Functions

// void menu(void);
// Prints Out menu to the user then retruns options chosen
// Parameter 1: void
// return: short number
void menu(void)
{
	// Printing
	std::cout << "\n1.Input Data" << std::endl;
	std::cout << "2.Calculate BMI" << std::endl;
	std::cout << "3.Save Data" << std::endl;
	std::cout << "4.Close Program" << std::endl;
} // End menu

// void option_menu(void);
// Reads user input and calls the related function/s
// Parameter 1: void
void option_menu(bool *menu_status)
{	
	// Vars
	char option = ' ';
	static class person_details person; // Dont lose Access to information

	// Reading option from user
	std::cout << "\nChoose Option: ";
	std::cin >> option;


	// Switch
	switch (option)
	{
		case '1':
		{
			// Read user data into a 
			read_user_data(&person);

			break;
		} // end case 1

		case '2':
		{
			// Calculate BMI
			calculate_BMI(&person);

			std::cout << "\nBMI Calculated: ";
			std::cout << person.BMI << std::endl;
			break;
		} // end case 2

		case '3':
		{
			// Ending Program
			std::cout << "\nSaving Data" << std::endl;
			save_data(&person);

			break;
		} // end case 3
		case '4':
		{
			std::cout << "Program End" << std::endl;
			*menu_status = false;

			break;
		} // End case 4
		default:
		{
			std::cout << "\nInvalid Option" << std::endl;
		} // End default
	} // End switch
} // End void option_menu(void)

// void read_user_data(void)
// Reads user data
void read_user_data(class person_details* person)
{
	// Input user data
	std::cout << "\nFirst Name: ";
	clearbuffer();
	std::cin.getline(person->firstname, NAME_SIZE);

	std::cout << "\nLast Name: ";
	std::cin.getline(person->lastname, NAME_SIZE);

	std::cout << "\nAge: ";
	std::cin >> person->age;

	std::cout << "\nHieght (m): ";
	std::cin >> person->height;

	std::cout << "\nWeight (kg): ";
	std::cin >> person->weight;
} // End void read_user_data(void)

// void calculate_BMI(class person_details*)
// Calculates BMI of user
// Parameter 1: person_detials pointer to access memory without creating copy
void calculate_BMI(class person_details* person)
{
	// Calculate BMI
	person->BMI = person->weight / (person->height * person->height);
} // End void calculate_BMI(class person_details*)


void save_data(class person_details* person)
{
	// Vars
	std::ofstream file;
	
	file.open("BMI_Calculations.txt");

	// Error Checking
	if (file.is_open())
	{
		file << person->firstname;
		file << " ";
		file << person->lastname;
		file << " ";
		file << person->age;
		file << " ";
		file << person->height;
		file << " ";
		file << person->weight;
		file << " ";
		file << person->BMI;
	} // End if
	else
	{
		std::cout << "Cant open File" << std::endl;
	} // End else

	file.close();
	// Opening Files
} // void save_data(class person_details*)

// void clearbuffer(void)
// Clear input buffer
void clearbuffer(void)
{
	while (getchar() != '\n');
} // End void clearbuffer(void);
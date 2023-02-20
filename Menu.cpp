/*
 * Menu.cpp
 *
 *  Created on: Feb 19, 2023
 *      Author: zach beachy
 */


#include "Menu.h"


#include<iostream>
#include<iomanip>
#include<string>

Menu::Menu()
{
 m_isActive = true;
 m_HEADER_BOLD = nCharString(62, '*');
 m_HEADER_SUB = nCharString(62, '=');
}

//Utility function that takes a length and a char and builds a string of the specified length with the specified character
std::string Menu::nCharString(int t_len, char t_replacer)
{

	std::string chStr;


	for( int i = 0; i < t_len; i++) {
		chStr += t_replacer;
	}

	return chStr;
}

/*
 * Utility function that takes a string and returns it in lower case to avoid case issues in user input
 */
std::string Menu::LowerCase(std::string t_rawInput)
{
	std::string modifiedInput = t_rawInput;

	for(int i = 0; i < t_rawInput.size(); i++)
	{
		modifiedInput.at(i) = tolower(t_rawInput.at(i));
	}


	return modifiedInput;
}
//Utility function that returns the amount of characters of the largest named object in the vector. This is for formatting the histo plot
int Menu::LargestSizeName(std::vector<ItemFreq> t_dataList)
{
	int largestSizeString = 1;

	for(int i = 0; i < t_dataList.size(); i++)
	{
		if(t_dataList.at(i).GetName().size() > largestSizeString)
		{
			largestSizeString = t_dataList.at(i).GetName().size();
		}
	}

	return largestSizeString;
}
//utility function that returns the largest frequency purchase of items. This is for formatting the histo plot
int Menu::LargestSizeFreq(std::vector<ItemFreq> t_dataList)
{
	unsigned int largestSizeFreq = 0;

	for(int i = 0; i < t_dataList.size(); i++)
	{
		if(t_dataList.at(i).GetFreq() > largestSizeFreq)
		{
			largestSizeFreq = t_dataList.at(i).GetFreq();
		}
	}

	return largestSizeFreq;
}
//utility function that computes the average purchase number. This is for displaying in the histo/ raw output menu
float Menu::ComputeAvg(std::vector<ItemFreq> t_dataList)
{
	float avg = 0;

	for(int i = 0; i < t_dataList.size(); i++)
	{
		avg += t_dataList.at(i).GetFreq();
	}
	avg = avg/t_dataList.size();

	return avg;
}

//Utility function that finds the names of the most purchased items. This is for displaying in the histo/raw output menu
std::string Menu::MostPurchased(std::vector<ItemFreq> t_dataList)
{
	int highFreq = LargestSizeFreq(t_dataList);
	std::vector<std::string> ifMultiple;
	std::string result;

	for(int i = 0; i < t_dataList.size(); i++)
	{
		if(t_dataList.at(i).GetFreq() == highFreq)
		{
			ifMultiple.push_back(t_dataList.at(i).GetName());
		}
	}
	for(int i = 0; i < ifMultiple.size(); i++)
	{
		if(i == ifMultiple.size()- 1)
		{
			result += ifMultiple.at(i);
		}
		else
		{
			result += ifMultiple.at(i) + ", ";
		}
	}
	return result;
}

/*
 * Main Menu print function. This prints the home screen
 */
void Menu::MainMenu()
{
	{

		std::string headerTitle = nCharString(24, '*');

		std::cout << m_HEADER_BOLD << std::endl << headerTitle << " Grocer Sales " << headerTitle << std::endl << std::endl <<
			"Please Select an Option:" << std::endl << std::endl << "1) Search item\n" << std::endl << "2) Print list of items\n"
			<< std::endl << "3) Print item histogram\n" << std::endl << "4) Exit\n" << std::endl <<  m_HEADER_BOLD << std::endl;

	}
}

//Prints the header to the option 1: search item menu
void Menu::SearchMenu()
{

	std::string headerTitle = nCharString(24, '*');

	std::cout << m_HEADER_SUB << std::endl << headerTitle << " Item Search " << headerTitle << '*' << std::endl << std::endl <<
		"Please enter an item: " << std::endl;
}
//Prints the header to the option 2: print list of items menu
void Menu::RawOutputMenu()
{
	std::string headerTitle = nCharString(18, '*');

	std::cout << m_HEADER_SUB << std::endl << headerTitle << " Item/Purchase Frequency " << headerTitle << '*' <<  std::endl << std::endl;
}
//Prints header to the option 3: print item histogram menu
void Menu::HistoMenu()
{
	std::string headerTitle = nCharString(25, '*');

	std::cout << m_HEADER_SUB << std::endl << headerTitle << " Histogram " << headerTitle << '*' << std::endl << std::endl;
}


/*
 * This is the navigator. It drives all user input within the menu object and calls the scripts that are needed to output the requested
 * information to the console. It takes a vector of type ItemFreq which it passes to other functions to use for computations and the like
 * for the outputs.
 */
void Menu::MenuNavigator(std::vector<ItemFreq> t_dataList)
{
	bool menuReturn = true;
	char userSelection;
	int i;

	while(menuReturn)
	{
		MainMenu();
		std::cin >> userSelection;
		bool subMenuReturn = true;

		switch(userSelection)
		{
		case '1':
			/*
			 * Case 1 allows the user to search for items on the list and find the frequency, it additionally allows the user to search
			 * multiple times if desired. Once the user is done, it will return to the main menu.
			 */
			while(subMenuReturn)
			{
				SearchMenu();

				std::string userSearch;
				char userReplay;
				bool isFound = false;

				std::cin >> userSearch;
				userSearch = LowerCase(userSearch);


				for(i = 0; i < t_dataList.size(); i++)
				{
					if(LowerCase(t_dataList.at(i).GetName()) == userSearch)
					{
						std::cout << "Item Found:" << std::endl;
						t_dataList.at(i).PrintItem();
						isFound = true;
						break;
					}
				}
				if(!isFound)
				{
					std::cout << "Item not found." << std::endl;
				}

				//This nested switch statement is so the user can search additional items if desired
				std::cout << m_HEADER_BOLD << std::endl << "Would you like to search for another item? (Y/N)" << std::endl;
				std::cin >> userReplay;
				userReplay = tolower(userReplay);

				switch(userReplay)
				{

				case 'y':

					break;
				case 'n':
					subMenuReturn = false;
					break;
				default:
					std::cout << "Invalid selection. Please enter Y or N.";
					break;
				}


			}
			break;

			/*
			 * Case 2 prints the raw formatted output that is also contained in the output file. It then returns to the main menu
			 */
		case '2':
			while(subMenuReturn)
			{
				RawOutputMenu();
				for(i = 0; i < t_dataList.size(); i++)
				{
					t_dataList.at(i).PrintItem();
				}
				std::cout << std::endl << "Average # of Purchases/ Item: " << std::fixed << std::setprecision(2) << ComputeAvg(t_dataList) << std::endl <<
						"Most Purchased Item(s): " << MostPurchased(t_dataList) << std::endl << std::endl;

				subMenuReturn = false;
			}
			break;

			/*
			 * Case 3 prints the histogram plot and then returns to the main menu
			 */
		case '3':
			while(subMenuReturn)
			{
				HistoMenu();
				int headWidthSetting = (LargestSizeName(t_dataList) + 3);

				/*
				 * The 18 here is in reference to the length of the string "Avg Purchases/Item" Basically, this value formats the y-axis labels
				 * on the plot. It will adjust based on the length of the names of items so that it is still formatted correctly. If the items
				 * are named shorter than the 18 value, a default setting must be set so that the plot doesn't break in formatting
				 */
				if(headWidthSetting < 18)
				{
					headWidthSetting = 20;
				}
				int xWidthSetting = LargestSizeFreq(t_dataList);

				for(i = 0; i < t_dataList.size(); i++)
				{
					std::cout << std::setw(headWidthSetting) << t_dataList.at(i).GetName() << "| " << nCharString(t_dataList.at(i).GetFreq(), '*') <<
						std::endl;
				}
				std::cout << std::setw(headWidthSetting) << " " << "+" << nCharString((xWidthSetting + 15), '-') << std::endl << std::setw(headWidthSetting) <<
						"Frequency"<< "| ";

				int xNum = 5;
				for(i = 0; i < xWidthSetting + 5; i += 5)
				{
					std::cout << nCharString(4, ' ') << xNum;
					xNum +=5;
				}
				std::cout << std::endl << std::setw(headWidthSetting) << " " << "+" << nCharString((xWidthSetting + 15), '-') << std::endl <<
						std::setw(headWidthSetting) << "Avg Purchases/Item" << "| " << std::fixed << std::setprecision(2) << ComputeAvg(t_dataList) <<
						std::endl << std::setw(headWidthSetting) << "Most Purchased" << "| " << MostPurchased(t_dataList) << std::endl << std::endl;

				subMenuReturn = false;
			}

			break;

			/*
			 * Case 4 is how the user exits the program
			 */
		case '4':

			std::cout << "Goodbye.";
			menuReturn = false;
			break;

			/*
			 * This exists for error checking, essentially if the user makes a mistake on input this will catch it and return to the main menu
			 */
		default:

			std::cout << "Invalid Selection. Please input a number corresponding to the action you wish to take." << std::endl;
			break;
		}


	}
}




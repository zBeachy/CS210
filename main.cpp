/*
 * main.cpp
 *
 *  Created on: Feb 18, 2023
 *      Author: zach beachy
 */

#include "ItemFreq.h"
#include "Menu.h"
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;


void itemCounter(vector<string> items, vector<ItemFreq> &t_outList);
void formatData(vector<ItemFreq> &t_master);





int main()
{
	vector<ItemFreq> masterList;
	Menu nav;
	formatData(masterList);
	nav.MenuNavigator(masterList);




	return 0;
}




/*
 * Counts items if they have been seen before in the original unformatted list. It adds each formatted item to the master vector
 */
void itemCounter(vector<string> t_items, vector<ItemFreq> &t_outList)
{

	vector<bool> hasBeenSeen(t_items.size(), false);
	ItemFreq tempItem("Test", -1);

	//Counts frequency of items and builds objects for each item
	for(int index = 0; index < t_items.size(); index++)
	{
		if(hasBeenSeen.at(index) == true)
		{
			continue;
		}

		int count = 1;
		for(int indexTwo = index + 1; indexTwo < t_items.size(); ++indexTwo)
		{
			if(t_items.at(index) == t_items.at(indexTwo))
			{
				hasBeenSeen.at(indexTwo) = true;
				count++;
			}
		}

		tempItem.SetName(t_items.at(index));
		tempItem.SetFreq(count);
		t_outList.push_back(tempItem);


	}

}
/*
 * Opens the input file, stores the items in a vector called fileRead, then calls the itemCounter function to figure out item frequency
 * It then outputs the reformatted data in "frequency.dat"
 */
void formatData(vector<ItemFreq> &t_master)
{

	//variable declarations

	vector<string> fileRead;
	string tempName;
	ifstream inFile;
	ofstream outFile;


	inFile.open("CS210_Project_Three_Input_File.txt");

	if(!inFile.is_open())
	{
		cout << "Could not open input file. Please ensure file is titled \"input.txt\"" << endl;
	}
	else
	{
		//Collects the data from the input file
		while(!inFile.fail() && !inFile.eof())
		{
			inFile >> tempName;
			fileRead.push_back(tempName);
		}
		inFile.close();


		itemCounter(fileRead, t_master);

		outFile.open("frequency.dat");

		if(!outFile.is_open())
		{
			cout << "Could not open output file. Please ensure file is titled \"frequency.dat\"" << endl;
		}
		else
		{
			for(int index = 0; index < t_master.size(); index++)
				{
					outFile << t_master.at(index).GetName() <<" "<< t_master.at(index).GetFreq() << endl;

				}
			outFile.close();
		}


	}
}




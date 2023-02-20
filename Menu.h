/*
 * Menu.h
 *
 *  Created on: Feb 19, 2023
 *      Author: zach beachy
 */

#ifndef MENU_H_
#define MENU_H_

#include "ItemFreq.h"
#include<iostream>
#include<vector>

class Menu
{
	private:
	std::string nCharString(int t_len, char t_replacer);
	std::string LowerCase(std::string t_rawInput);
	std::string MostPurchased(std::vector<ItemFreq> t_dataList);
	int LargestSizeName(std::vector<ItemFreq> t_dataList);
	int LargestSizeFreq(std::vector<ItemFreq> t_dataList);
	float ComputeAvg(std::vector<ItemFreq> t_dataList);
	bool m_isActive;
	std::string m_HEADER_BOLD;
	std::string m_HEADER_SUB;

	public:
	Menu();

	void MainMenu();
	void SearchMenu();
	void RawOutputMenu();
	void HistoMenu();

	void MenuNavigator(std::vector<ItemFreq> t_dataList);
};



#endif /* MENU_H_ */

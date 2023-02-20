/*
 * ItemFreq.cpp
 *
 *  Created on: Feb 18, 2023
 *      Author: zach beachy
 */

#include "ItemFreq.h"
#include<iostream>

//Constructor
ItemFreq::ItemFreq(std::string t_itemName, int t_numRepeat=1)
{
	m_itemName = t_itemName;
	m_frequency = t_numRepeat;
}


//Getters
std::string ItemFreq::GetName()
{
	return m_itemName;
}

int ItemFreq::GetFreq()
{
	return m_frequency;
}

//Setters
void ItemFreq::SetName(std::string newName)
{
	m_itemName = newName;
}
void ItemFreq::SetFreq(int newFreq)
{
	m_frequency = newFreq;
}

void ItemFreq::IncFreq()
{
	m_frequency++;
}
//Prints item details
void ItemFreq::PrintItem()
{
	std::cout << m_itemName << ", " << m_frequency << std::endl;
}


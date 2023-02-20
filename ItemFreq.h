/*
 * ItemFreq.h
 *
 *  Created on: Feb 18, 2023
 *      Author: zach beachy
 */

#ifndef ITEMFREQ_H_
#define ITEMFREQ_H_

#include<iostream>

class ItemFreq
{
	private:
		std::string m_itemName;
		int m_frequency;

	public:

		//constructor
		ItemFreq(std::string t_itemName, int t_numRepeat);

		std::string GetName();
		int GetFreq();

		void SetName(std::string newName);
		void SetFreq(int newFreq);

		void IncFreq();

		void PrintItem();







};



#endif /* ITEMFREQ_H_ */

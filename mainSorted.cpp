
#include <iostream>
#include <string>
#include "sortedList.h"
#include "sorted.cpp"

using namespace std;

int main()
{
	cout << "\tThis program implements ADT sorted list\n";
	
	sorted<string> sortedData;
	string tempData;

	char select = ' ';
	cout << "Menu:\n"
		<< "\tEnter I or i for inserting a name\n"
		<< "\tEnter R or r for removing a name\n"
		<< "\tEnter L or l to find the number of saved arrays\n"
		<< "\tEnter G or g to retrieve a data\n"
		<< "\tEnter P or p to get the position of a value\n"
		<< "\tEnter S or s to show all the contents\n"
		<< "\tEnter Q or q to quit from the program\n\n";


	do{
		cout << "Enter your choice: ";
		cin >> select;

		switch (toupper(select))
		{
		case 'I':
		{
			cout << "Enter a name: ";
			cin >> tempData;

			if (sortedData.sortedInsert(tempData))
				cout << "Your value has been successfully added\n";
			else
				cout << "Memeory is full, Try deleting a value\n";

		}
			break;

		case 'R':
		{
			cout << "Enter the name you want to delete: ";
			cin >> tempData;
			if (sortedData.sortedRemove(tempData))
				cout << tempData << " has been successfully deleted\n";
			else
				cout  << "Couldnt find " << tempData << ". Try again\n";
		}
			break;
		case 'L':
		{
			cout << "You have used " << sortedData.sortedGetLength() << " memory spaces of the total " << sortedData.sortedMaxLength() << " memory spaces" << endl;
		}
			break;
		case 'G':
		{
			int dataV;
			cout << "Which index value would you like to retrive: ";
			cin >> dataV;
			sortedData.sortedRetrive(dataV, tempData);
			cout << "The vaue you are looking for at "<<dataV <<" is " << tempData << endl;
		}
			break;
		case 'P':
		{
			cout << "Which value do you want to get the value of: ";
			cin >> tempData;
			if (sortedData.locatePosition(tempData)>-1)
				cout << "\n The value you were looking for is at " << sortedData.locatePosition(tempData) << " position" << endl;
			else 
				cout << "Couldnt find " << tempData << ".Try again\n";
		}
			break;
		case 'S':
			cout << "These are the values you entered in order from least to greatest\n";
			sortedData.listSortedArray();
			break;

		case 'Q':
			cout << "\nGood bye";
			break;

		default:
			cout << "Invalid input,Try again\n";
			break;
		}
		cin.get();
	} while (toupper(select) != 'Q');
	
	cin.get();
	return 0;
}


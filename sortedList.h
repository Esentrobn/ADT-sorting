#ifndef _SORTED
#define _SORTED


#include <string>
#include "sortedListInterface.h"

using namespace std;

template<class ListItemType>


class sorted : public sortedInterface<ListItemType>
{
public:
	sorted();
	bool sortedIsEmpty() const;
	int sortedMaxLength() const;
	int sortedGetLength() const;
	void listSortedArray() const;
	bool sortedInsert(const ListItemType& newItem);
	bool sortedRemove(const ListItemType& anItem);
	int locatePosition(const ListItemType& anItem) const;
	bool sortedRetrive(int index, ListItemType& dataItem) const; // nothing should be left unchanged

private:
	
	static const int DEFAULT_BAG_SIZE = 10;
	ListItemType items[DEFAULT_BAG_SIZE]; // array of list items
	int itemCount;                    // current count of list items 
	int maxItems;                     // max capacity of the list

};


#endif

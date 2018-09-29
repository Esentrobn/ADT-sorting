#include "stdafx.h"
#include <string>
#include "sortedList.h"

template<class ListItemType>
sorted<ListItemType>::sorted() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{}  // end default constructor

template<class ListItemType>
bool sorted<ListItemType>::sortedIsEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ListItemType>
int sorted<ListItemType>::sortedMaxLength() const
{
	return maxItems;
}  // end isEmpty

template<class ListItemType>
int sorted<ListItemType>::sortedGetLength() const
{
	return itemCount;
}  // end getCurrentSize

template<class ListItemType>
void  sorted<ListItemType>::listSortedArray() const
{
	for (int i = 0; i < sortedGetLength(); i++)
		cout << items[i] << " ";

	if (sortedGetLength() == 0)
		cout << "Empty list";
	cout << endl;
}

template<class ListItemType>
bool sorted<ListItemType>::sortedInsert(const ListItemType& newItem)
{

	bool hasRoomToAdd = (itemCount < maxItems);

	if (hasRoomToAdd)
	{
		int count = itemCount;

		// compare with the last value and shift based on that
		while (count >= 0)
		{
			if (count != 0)
			{
				if (items[count - 1] > newItem)//if (strcmp(items[count - 1], newItem)==-1)//
				{
					items[count] = items[count - 1];
					count--;
				}
				else
				{
					items[count] = newItem;
					break;
				}
			}
			else
			{
				items[count] = newItem;
				break;
			}
		}

		itemCount++;
	}

	return hasRoomToAdd;
}

template<class ListItemType>
bool sorted<ListItemType>::sortedRemove(const ListItemType& anItem)
{


	//ListItemType temp;
	int curPos = locatePosition(anItem);

	bool canRemove = false;
	int count = curPos;// item count value since we increament at last

	if (curPos > -1)
	{
		ListItemType temp;//= items[count - 1];

		while (count < itemCount - 1)
		{

			//temp = items[count - 1];
			items[count] = items[count + 1];

			//items[count - 1] = ite;
			count++;
		}

		itemCount--;
		canRemove = true;
	}

	return canRemove;
}

template<class ListItemType>
bool sorted<ListItemType>::sortedRetrive(int index, ListItemType& dataItem) const
{
	bool success = index >= 1 && index < sortedGetLength();

	if (success)
		dataItem = items[index];

	return success;
}

template<class ListItemType>
int sorted<ListItemType>::locatePosition(const ListItemType& anItem) const
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;
	// if the bag is empty, itemCount is zero, so loop is skipped
	while (!found && (searchIndex < itemCount))
	{
		if (items[searchIndex] == anItem)
		{
			found = true;
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		}  // end if
	}  // end while

	return result;
}  // end getIndexOf

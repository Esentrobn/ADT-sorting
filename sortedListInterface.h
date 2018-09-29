#ifndef SORTEDINTERFACE
#define SORTEDINTERFACE
using namespace std;

template<class ListItemType>
class sortedInterface
{
public:
	/** Sees whether this array is empty.
	@return True if the array is empty, or false if not. */

	virtual bool sortedIsEmpty() const = 0;

	/** gets the max lenfth of the array
	@return the max length of the sorted array. */

	virtual int sortedMaxLength() const = 0;

	/** Gets the current number of entries in this array.
	@return The integer number of entries currently in the array. */

	virtual int sortedGetLength() const = 0;

	/** Adds a new entry to this sorted array.
	@post  If successful, newEntry is stored in the array and
	the count of items in the bag has increased by 1.
	@param newItem  The object to be added as a new entry.
	@return  True if addition was successful, or false if not. */

	virtual bool sortedInsert(const ListItemType& newItem) = 0;

	/** Removes one occurrence of a given entry from this sorted array,
	if possible.
	@post  If successful, anItem has been removed from the sorted array
	and the count of items in the sorted array has decreased by 1.
	@param anItem  The entry to be removed.
	@return  True if removal was successful, or false if not. */

	virtual bool sortedRemove(const ListItemType& anItem) = 0;

	/** gets the position anItem belongs
	@post  If successful, anItem has been removed from the sorted array
	and the count of items in the sorted array has decreased by 1.
	@param anItem  The entry to be located.
	@return  Returns the position where anItem belongs or exists in this sorted list. The item anItem and the list are unchanged */

	virtual int locatePosition(const ListItemType& anItem) const = 0;

	/** takes the index and saves the value found to dataItem. 
	
	@param index  The index to be found
	@param dataItem If index is 1 ? index ? sortedGetLength(), dataItem to the item
	@return  True if retrival was successful, or false if not. */

	virtual bool sortedRetrive(int index, ListItemType& dataItem) const = 0;

	/*  outputs all the datas saved in the arrray */
	virtual void listSortedArray() const = 0;

};

#endif
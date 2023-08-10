// FILE: table2.tpp.h
// TEMPLATE CLASS IMPLEMENTED: Table (see table2.h for documentation)
// INVARIANT for the Table ADT:
//   1. The number of records in the Table is in the member variable
//      total_records.
//   2. The actual records of the table are stored in a chained hash table.
//      An entry with key i is stored on the linked list with the head
//      pointer at data[hash(i)].
// 
//Raj Shah, rshah39@mywvm.wvm.edu

#include <assert.h> // Provides assert

template <class RecordType>
size_t Table<RecordType>::hash_function(int key) const
{
	return (key % TABLE_SIZE);
}

template <class RecordType>
Table<RecordType>::Table( )
{
	size_t i;

	total_records = 0;
	// Initilize the head pointer for every linked list
	for (i = 0; i < TABLE_SIZE; i++)
		hash_table[i] = nullptr;
}

template <class RecordType>
Table<RecordType>::~Table( )
// Library facilities used: link2.h
{
	size_t i;
	Node<RecordType>* cursor;
	total_records = 0;
// Delete every linked list
// *** To be implemented by students ***
	for (i = 0; i < TABLE_SIZE; i++) {
		cursor = hash_table[i];
		while (cursor != nullptr) {
			Node<RecordType>* linkBank;
			linkBank = cursor->link;
			delete cursor;
			cursor = linkBank;
		}
		hash_table[i] = nullptr;
	}
	
}

template <class RecordType>
Table<RecordType>::Table(const Table<RecordType>& source) 
{
	size_t i;
	// Copy every linked list from the source hash_table to the destination
// *** To be implemented by students ***
	// Initilize the head pointer for every linked list
	Node<RecordType>* cursor;
	total_records = 0;
	for (i = 0; i < TABLE_SIZE; i++) {
		cursor = source.hash_table[i];
		hash_table[i] = nullptr;
		while (cursor != nullptr) {
			insert(cursor->data);
			cursor = cursor->link;
		}
	}
}


template <class RecordType>
void Table<RecordType>::insert(const RecordType& entry)
{
	Node<RecordType>* cursor; // set to point to existing Node with given key
	assert(entry.key >= 0);
	// Set cursor to point to existing Node with given key (if there is one)
// *** To be implemented by students ***
	int index = hash_function(entry.key);
	cursor = hash_table[index];
	if (cursor == nullptr) {
		Node<RecordType> *insertNode = new Node<RecordType>() ;
		insertNode->link = nullptr;
		insertNode->data = entry;
		hash_table[index] = insertNode;
		++total_records;
		return;
	}
	while (true){
		if (entry.key == cursor->data.key) {
			cursor->data = entry;
			return;
		}
		if (cursor->link == nullptr) {
			Node<RecordType>* insertNode = new Node<RecordType>();
			insertNode->link = nullptr;
			insertNode->data = entry;
			cursor->link = insertNode;
			++total_records;
			return;
		}
		cursor = cursor->link;
	}
}

template <class RecordType>
void Table<RecordType>::remove(int key)
{
	Node<RecordType> *cursor;    // Points to existing Node with given key
	Node<RecordType> *precursor; // Points to node before the cursor
	assert(key >= 0);
	// Set cursor to point to existing Node with given key (if there is one)
// *** To be implemented by students ***
	int index = hash_function(key);
	cursor = hash_table[index];
	precursor = nullptr;
	while (cursor != nullptr) {
		if (key == cursor->data.key) {
			if (precursor == nullptr) {
				hash_table[index] = cursor->link;
				delete cursor;
				--total_records;
				return;
			}
			precursor->link = cursor->link;
			delete cursor;
			--total_records;
			return;
		}
		precursor = cursor;
		cursor = cursor->link;
	}
}

template <class RecordType>
void Table<RecordType>::operator =(const Table<RecordType>& source) 
{
	size_t i;
	// Self Assignment
	// Deleted Destination has_table (every list)
	// Copy every linked list from the source hash_table to the destination
// *** To be implemented by students ***
	if (&source == this) {
		return;
	}
	Node<RecordType>* cursor;
	for (i = 0; i < TABLE_SIZE; i++) {
		cursor = hash_table[i];
		while (cursor != nullptr) {
			Node<RecordType>* linkBank;
			linkBank = cursor->link;
			delete cursor;
			cursor = linkBank;
		}
		hash_table[i] = nullptr;
	}

	
	total_records = 0;
	for (i = 0; i < TABLE_SIZE; i++) {
		cursor = source.hash_table[i];
		hash_table[i] = nullptr;
		while (cursor != nullptr) {
			insert(cursor->data);
			cursor = cursor->link;
		}
	}
}

template <class RecordType>
bool Table<RecordType>::is_present(int key) const
{
	assert(key >= 0);
// *** To be implemented by students ***
	bool found;
	RecordType nobodyCares;
	find(key, found, nobodyCares);
	return found;  //  Student need to return correct value
}

template <class RecordType>
void Table<RecordType>::find(int key, bool& found, RecordType& result) const
{
	Node<RecordType> *cursor;
// *** To be implemented by students ***
	int index = hash_function(key);
	cursor = hash_table[index];
	if (cursor == nullptr) {
		found = false;
		return;
	}
	while (cursor != nullptr){
		if (key == cursor->data.key) {
			result = cursor->data;
			found = true;
			return;
		}
		cursor = cursor->link;
	}
	found = false;
}

template <class RecordType>
Node<RecordType>* Table<RecordType>::find_node(int key) const
// Postcondition: The return value is a pointer to the record with the
// specified key (if there is one). If there is no such node, the return value
// is the nullptr pointer.
{}


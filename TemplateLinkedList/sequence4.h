// FILE: sequence3.h
//
//  Updated by Howard Miller on 3/01/23.
//  Copyright � 2019, 2020, 2021, 2023 Howard Miller. All rights reserved.
//
// CLASS PROVIDED: sequence (part of the namespace main_savitch_5)
// This is the header file for the project described in Section 5.4
// of "Data Structures and Other Objects Using C++"
// This is called "sequence3" because some students already implemented
// sequence1 (with a fixed array) and sequence2 (with a dynamic array).
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ T
//     sequence::T is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
// CONSTRUCTOR for the sequence class:
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const T& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const T& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and
//     the item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   T current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
#pragma once
#ifndef MAIN_SAVITCH_SEQUENCE4_H
#define MAIN_SAVITCH_SEQUENCE4_H
#include "node2.h"  // Provides node class
#include <cstdlib> // Provides size_t
namespace main_savitch_6B {
	template <typename T>
	class sequence
	{
	public:
		// CONSTRUCTORS and DESTRUCTOR
		sequence();
		sequence(const sequence<T>& source);
		~sequence();
		// MODIFICATION MEMBER FUNCTIONS
		void start();
		void advance();
		void insert(const T& entry);
		void attach(const T& entry);
		void operator =(const sequence<T>& source);
		void remove_current();
		// CONSTANT MEMBER FUNCTIONS
		size_t size() const { return many_nodes; }
		bool is_item() const { return (cursor != nullptr); }
		T current() const;
	private:
		node<T>* head_ptr;
		node<T>* tail_ptr;
		node<T>* cursor;
		node<T>* precursor;
		size_t many_nodes;
	};
} // End of namespace
//#include "sequence4.tpp.h" Uncommenting this causes a circular error, unsure why
#endif

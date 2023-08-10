#pragma once
#include <iostream>
#include "node2.h"
#include "sequence4.h"
#include <assert.h>

namespace main_savitch_6B {
	template <typename T> sequence<T>::sequence() {
		head_ptr = nullptr;
		tail_ptr = nullptr;
		cursor = nullptr;
		precursor = nullptr;
		many_nodes = 0;
	}

	template <typename T> sequence<T>::sequence(const sequence<T>& source) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.size();
		node<T>* stemp = source.head_ptr;
		node<T>* dtemp = head_ptr;

		while (dtemp != nullptr) {
			if (source.precursor == stemp) {
				precursor = dtemp;
			}
			if (source.cursor == stemp) {
				cursor = dtemp;
			}
			stemp = stemp->link();
			dtemp = dtemp->link();
		} 
	}

	template <typename T> sequence<T>::~sequence() {
		node<T>* temp;
		while (head_ptr != nullptr) {
			temp = head_ptr->link();
			delete head_ptr;
			head_ptr = temp;
		}
	}

	template <typename T> void sequence<T>::start() {
		cursor = head_ptr;
		precursor = nullptr;
	}

	template <typename T> void sequence<T>::advance() {
		assert(is_item());
		precursor = cursor;
		if (cursor->link() != nullptr) {
			cursor = cursor->link();
		}
		else {
			cursor = nullptr;
		}
	}

	template <typename T> void sequence<T>::insert(const T& entry) {
		node<T>* add_node = new node<T>(entry);
		if (head_ptr == nullptr) {
			head_ptr = add_node;
			tail_ptr = add_node;
			
		}
		else if (cursor == nullptr or cursor == head_ptr) {
			add_node->set_link(head_ptr);
			head_ptr = add_node;
		}
		else {
			add_node->set_link(cursor);
			if (cursor != head_ptr) {
				precursor->set_link(add_node);
			}
		}
		cursor = add_node;
		++many_nodes;

	}

	template <typename T> void sequence<T>::attach(const T& entry) {
		node<T>* add_node = new node<T>(entry);
		if (head_ptr == nullptr) {
			head_ptr = add_node;
			tail_ptr = add_node;
		}
		else if (cursor == nullptr) {
			tail_ptr->set_link(add_node);
			tail_ptr = add_node;
		}
		else {
			precursor = cursor;
			add_node->set_link(cursor->link());
			cursor->set_link(add_node);
			if (cursor == tail_ptr) {
				tail_ptr = add_node;
			}

		}
		cursor = add_node;
		++many_nodes;
	}

	template <typename T> void sequence<T>::operator =(const sequence<T>& source) {
		if (&source == this) {
			return;
		}
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.size();
		node<T>* temp = head_ptr;
		node<T>* stemp = source.head_ptr;
		node<T>* dtemp = head_ptr;

		while (dtemp != nullptr) {
			if (source.precursor == stemp) {
				precursor = dtemp;
			}
			if (source.cursor == stemp) {
				cursor = dtemp;
			}
			stemp = stemp->link();
			dtemp = dtemp->link();
		}
	}

	template <typename T> void sequence<T>::remove_current() {
		assert(is_item());
		if (head_ptr->link() == nullptr) {
			delete cursor;
			head_ptr = nullptr;
			tail_ptr = nullptr;
			cursor = nullptr;
			precursor = nullptr;
		}
		else if (cursor == head_ptr) {
			head_ptr = cursor->link();
			delete cursor;
			cursor = head_ptr;
		}
		else {
			precursor->set_link(cursor->link());
			delete cursor;
			if (precursor->link() == nullptr) {
				tail_ptr = precursor;
			}
			cursor = precursor->link();

		}
		--many_nodes;
	}
	template <typename T> T sequence<T>::current() const {
		assert(is_item());
		return cursor->data();
	}
}
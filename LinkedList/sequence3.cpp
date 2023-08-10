#include <iostream>
#include "node1.h"
#include "sequence3.h"
#include <assert.h>

namespace main_savitch_5 {
	sequence::sequence() {
		head_ptr = nullptr;
		tail_ptr = nullptr;
		cursor = nullptr;
		precursor = nullptr;
		many_nodes = 0;
	}

	sequence::sequence(const sequence& source) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.size();
		node* stemp = source.head_ptr;
		node* dtemp = head_ptr;

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
	sequence::~sequence() {
		node* temp;
		while (head_ptr != nullptr) {
			temp = head_ptr->link();
			delete head_ptr;
			head_ptr = temp;
		}
	}

	void sequence::start() {
		cursor = head_ptr;
		precursor = nullptr;
	}

	void sequence::advance() {
		assert(is_item());
		precursor = cursor;
		if (cursor->link() != nullptr) {
			cursor = cursor->link();
		}
		else {
			cursor = nullptr;
		}
	}

	void sequence::insert(const value_type& entry) {
		node* add_node = new node(entry);
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

	void sequence::attach(const value_type& entry) {
		node* add_node = new node(entry);
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

	void sequence::operator =(const sequence& source) {
		if (&source == this) {
			return;
		}
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.size();
		node* temp = head_ptr;
		node* stemp = source.head_ptr;
		node* dtemp = head_ptr;

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

	void sequence::remove_current() {
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

	value_type sequence::current() const {
		assert(is_item());
		return cursor->data();
	}
}
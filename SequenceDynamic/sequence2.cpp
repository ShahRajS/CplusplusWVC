#include <iostream>
#include "sequence2.h"
#include <assert.h>

namespace main_savitch_4 {
	sequence::sequence(size_t initial_capacity) {
		used = 0;
		current_index = 0;
		capacity = initial_capacity;
		data = new value_type[initial_capacity];
	}

	sequence::sequence(const sequence& source) {
		current_index = source.current_index;
		used = source.used;
		capacity = source.capacity;
		data = new value_type[source.capacity];
		for (size_t i = 0; i < used; ++i) {
			data[i] = source.data[i];
		}
	}

	sequence::~sequence() {
		delete data;
	}

	void sequence::resize(size_t new_capacity) {
		if (capacity == new_capacity) {
			return;
		}
		if (new_capacity > used) {
			capacity = new_capacity;
		}
		else {
			capacity = used;
		}

		value_type* data_new = new value_type[capacity];
		for (size_t i = 0; i < used; ++i) {
			data_new[i] = data[i];
		}
		delete[] data;
		data = data_new;
	}

	void sequence::start() {
		if (used > 0) {
			current_index = 0;
		}
	}

	void sequence::advance() {
		assert(is_item());
		if (current_index != used) {
			++current_index;
		}
		return;
	}

	void sequence::insert(const value_type& entry) {
		if (used >= capacity) {
			resize((capacity * 1.5) + 1);
		}
		if (!is_item()) {
			current_index = 0;
		}
		for (size_t i = used; i > current_index; --i) {
			data[i] = data[i - 1];
		}
		data[current_index] = entry;
		++used;
	}

	void sequence::attach(const value_type& entry) {
		if (used >= capacity) {
			resize((capacity * 1.5) + 1);
		}
		if (!is_item()) {
			current_index = used;
		}
		else {
			++current_index;
		}

		for (size_t i = used; i > current_index; --i) {
			data[i] = data[i - 1];
		}
		data[current_index] = entry;
		++used;
	}

	void sequence::remove_current() {
		assert(is_item());
		for (size_t i = current_index + 1; i < used; ++i) {
			data[i - 1] = data[i];
		}
		--used;
	}

	size_t sequence::size() const {
		return used;
	}

	size_t sequence::max_size() const {
		return capacity;
	}

	bool sequence::is_item() const{
		return (current_index < size());
	}

	sequence::value_type sequence::current() const {
		assert(is_item());
		return(data[current_index]);
	}

	void sequence::operator= (const sequence& source) {
		value_type* new_data;
		if (this == &source) {
			return;
		}
		if (capacity != source.capacity) {
			new_data = new value_type[source.capacity];
			delete[] data;
			data = new_data;
			capacity = source.capacity;
		}
		used = source.used;
		current_index = source.current_index;
		for (size_t i = 0; i < used; ++i) {
			data[i] = source.data[i];
		}
	}

}
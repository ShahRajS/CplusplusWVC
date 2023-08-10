#include <iostream>
#include "sequence1.h"
#include <assert.h>

namespace main_savitch_3 {
	sequence::sequence() {
		current_index = 0;
		used = 0;
	}

	void sequence::start() {
		if (used > 0) {
			current_index = 0;
		}
	}
	void sequence::advance() {
		if (current_index != used) {
			++current_index;
		}
		else {
			return;
		}
	}

	void sequence::insert(const value_type& entry) {
		assert(size() < CAPACITY);
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
		assert(size() < CAPACITY);
		if (used < CAPACITY) {
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

	bool sequence::is_item() const {
		return (current_index < size());
	}

	sequence::value_type sequence::current() const{
		assert(is_item());
		return(data[current_index]);
	}
}